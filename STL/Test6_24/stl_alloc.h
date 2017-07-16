
//一级空间配置器

#if 0
#	include<new>
#	define __THROW_BAD_ALLOC throw bad_alloc
#elif !defined(__THROW_BAD_ALLOC)
#include<iostream>	
using namespace std;
#define __THROW_BAD_ALLOC cerr<<"out of memory"<<endl; exit(1)
#endif

//malloc-based allocator 通常比稍后介绍的default alloc速度慢
//一般而言是thread-safe 并且对于空间的运用比较高效(efficient)
//以下是第一级配置器
//注意。无"无template型别参数"，至于"非型别参数"inst，则完全没派上用场

template<int inst>
class __malloc_alloc_template
{
private:
	//以下函数用来处理内存不足的情况
	//oom : out of memory
	static void* oom_malloc(size_t);
	static void* oom_realloc(void*,size_t);
	static void (*__malloc_alloc_oom_handler) ();

public:
	static void* allocate(size_t n)
	{
		void* result = malloc(n);//第一级配置器直接使用malloc()
		//当需求无法被满足时，改用oom_malloc()
		if(0 == result);
			result = oom_malloc(n);
		return result;
	}

	static void deallocate(void* p,size_t n)//第一级配置器直接使用free();
	{
		free(p);
	}

	static void *reallocate(void* p,size_t old_sz,size_t new_sz)
	{
		void* result = realloc(p,new_sz);//第一级配置器直接使用realloc()
		//当以下无法满足时，改用oom_realloc()
		if(0 == result)
			result = oom_realloc(p,new_sz);
		return result;
	}
	
	//以下仿真C++的set_new_handler() 换句话说，你可以通过它
	//指定你自己的out_of_memory handler
	static void (* set_new_handler(void (*f)() ) ) ()
	{			//指针函数		//函数指针
				
		void (*old)() = __malloc_alloc_oom_handler;
		__malloc_alloc_oom_handler = f;
		return (old);
	}
};

	//malloc_alloc out_of_memory handling
	//初值为0 有待客户端设定
template<int inst>
void (* __malloc_alloc_template<inst>::__malloc_alloc_oom_handler) () = 0;

template<int inst>
void* __malloc_alloc_template<inst>::oom_malloc(size_t n)
{
	void (*my_malloc_handler)();
	void* result;

	for(;;)
	{	//不断尝试释放，配置，再释放，再配置
		my_malloc_handler = __malloc_alloc_oom_handler;
		if(0 == my_malloc_handler)
		{
			__THROW_BAD_ALLOC;
		}
		(*my_malloc_handler)();	//调用处理例程，企图释放内存
		result = malloc(n);		//再次尝试配置内存
		if(result)
			return result;
	}
}

template<int inst>
void* __malloc_alloc_template<inst>::oom_realloc(void* p,size_t n)
{
	void (*my_malloc_handler)();
	void* result;

	for(;;)
	{	//不断尝试释放 配置 再释放 再配置
		my_malloc_handler = __malloc_alloc_oom_handler;
		if(0 == my_malloc_handler)
		{
			__THROW_BAD_ALLOC;
		}
		(*my_malloc_handler)();		//调用处理例程 企图释放内存
		result = realloc(p,n);		//再次尝试释放内存
		if(result)
			return result;
	}
}

//注意 一下直接将参数inst指定为0
typedef __malloc_alloc_template<0> malloc_alloc;

/*******************************************/
//二级空间配置器

enum {__ALIGN = 8};				//小型区块的上调边界
enum {__MAX_BYTES = 128};		//小型区块的上限
enum {__NFREELISTS = __MAX_BYTES / __ALIGN};	//free_lists个数

//以下是第二级配置器
//注意 无"template型别参数"，且第二个参数完全没有排上用场
//第一参数用于多线程环境下

template<bool threads,int inst>
class __default_alloc_template
{
private:
	//ROUND_UP()将bytes上调至8的倍数
	static size_t ROUND_UP(size_t bytes)
	{	//__ALIGN必须是2的正次方
		return ( ( (bytes) + __ALIGN-1) & ~(__ALIGN - 1) );
	}
private:
	union obj
	{
		union obj* free_lists_link;
		char client_data[1];	//The client sees this
	};
private:
	//16个free_lists
	static obj* volatile free_list[__NFREELISTS];
	static size_t FREELIST_INDEX(size_t bytes)
	//以下函数根据区块大小，决定使用第n号free_list.n从0开始
	{
		return ( ( (bytes) + __ALIGN-1)/__ALIGN - 1);
	}
	//返回一个大小为n的对象，并可能加入大小为n的其他区块到free_list
	static void* refill(size_t n);

	//配置一块大空间，可容纳nobjs个大小为"size"的区块
	//如果配置nobjs个区块有所不便，nobjs可能会降低
	static char* chunk_alloc(size_t size,int &nobjs);

	//Chunk allocation state
	static char *start_free;		//内存池起始位置
	static char *end_free;			//内存池结束位置
	static size_t heap_size;

public:
	static void* allocate(size_t n);
	
	static void deallocate(void *p,size_t n);

	static void* reallocate(void *p,size_t old_sz,size_t new_sz);
};

template<bool threads,int inst>
char *__default_alloc_template<threads,inst>::start_free = 0;

template<bool threads,int inst>
char *__default_alloc_template<threads,inst>::end_free = 0;

template<bool threads,int inst>
size_t __default_alloc_template<threads,inst>::heap_size = 0;

template<bool threads,int inst>
typename __default_alloc_template<threads,inst>::obj* volatile __default_alloc_template<threads,inst>::free_list[__NFREELISTS] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

template<bool threads,int inst>
//n必须大于0
void* __default_alloc_template<threads,inst>::allocate(size_t n)
{	//volatile关键字所定义的变量 随时有可能得到改变
	obj* volatile *my_free_list;
	obj* result;
	//大于128就调用1级空间配置器
	if(n > (size_t) __MAX_BYTES)
		return (malloc_alloc::allocate(n));
	
	//寻找16个free list中适当的一个
	my_free_list = free_list + FREELIST_INDEX(n);
	result = *my_free_list;
	if(result == 0)
	{	//没找到可用的free list 准备重新填充free list
		void* r = refill(ROUND_UP(n));
		return r;
	}
	//调整free list
	*my_free_list = result->free_lists_link;
	return result;
}

template<bool threads,int inst>
void __default_alloc_template<threads,inst>::deallocate(void *p,size_t n)
{
	obj *q = (obj*)p;
	obj * volatile *my_free_list;

	//大于128就调用一级配置器
	if(n > (size_t) __MAX_BYTES)
	{
		malloc_alloc::deallocate(p,n);
		return;
	}

	//寻找对应的free list
	my_free_list = free_list + FREELIST_INDEX(n);
	//调整free list 回收区块
	q->free_lists_link = *my_free_list;
	*my_free_list = q;
}

//返回一个大小为n的对象，并且有时候会为适当的free list增加节点
//假设n已经适当上调至8的倍数
template<bool threads,int inst>
void* __default_alloc_template<threads,inst>::refill(size_t n)
{
	int nobjs = 20;
	//调用chunk_alloc(),尝试取得nobjs个区块作为free list的新节点
	//注意参数nobjs是pass by reference
	char* chunk = chunk_alloc(n,nobjs);
	obj* volatile *my_free_list;
	obj* result;
	obj* current_obj,*next_obj;
	int i;

	//如果只获得一个区块，这个区块就分配给调用者用，free list无新节点
	if(1 == nobjs)
		return chunk;
	my_free_list = free_list + FREELIST_INDEX(n);

	//以下在chunk空间内建立free list
	result = (obj*)chunk;	//这一块准备返回给客端
	//以下导引free list指向新配置的空间(取自内存池)
	*my_free_list = next_obj = (obj*)(chunk + n);
	//以下将free_list的各节点串接起来
	for(i = 1; ; ++i)
	{
		current_obj = next_obj;
		next_obj = (obj*)((char*)next_obj + n);
		if(nobjs - 1 == i)
		{
			current_obj->free_lists_link = 0;
			break;
		}
		else
		{
			current_obj->free_lists_link = next_obj;
		}
	}
	return result; 
}

//假设size已经适当上调至8的倍数
//注意参数nobjs是pass by reference
template<bool threads,int inst>
char* __default_alloc_template<threads,inst>::chunk_alloc(size_t size,int& nobjs)
{
	char* result;
	size_t total_bytes = size * nobjs;
	size_t bytes_left = end_free - start_free;	//内存池剩余空间

	if(bytes_left >= total_bytes)
	{//内存池剩余空间完全满足需求量
		result = start_free;
		start_free += total_bytes;
		return result;
	}
	else if(bytes_left >= size)
	{//内存池剩余空间不能完全满足需求量，但足够供应一个以上的区块
		nobjs = bytes_left/size;
		total_bytes = size * nobjs;
		result = start_free;
		start_free += total_bytes;
		return result;
	}
	else
	{//内存池连一个区块的大小都无法提供
		size_t bytes_to_get = 2 * total_bytes + ROUND_UP(heap_size >> 4);
	 //一下试着让内存池中的残余零头还有利用价值
	 if(bytes_left > 0)
	 {//内存池内还有一些零头 先配给适当的free_list
	  //首先寻找适当的free_list
	  obj* volatile *my_free_list = free_list + FREELIST_INDEX(bytes_left);
	  //调整free_list，将内存池中的残余空间编入
	  ((obj*)start_free)->free_lists_link = *my_free_list;
	  *my_free_list = (obj*)start_free;
	 }

	 //配置heap空间，用来补充内存池
	 start_free = (char*)malloc(bytes_to_get);
	 if(0 == start_free)
	 {//heap空间不足，mallo()失败
	 	int i;
		obj *volatile *my_free_list,*p;
		//试着检查我们手上拥有的东西，这不会造成伤害，我们不打算尝试配置
		//较小的区块，因为那在多进程(multi-process)机器上容易导致灾害
		//以下搜寻适当的free_list
		//所谓适当是指"尚有未用区块 且区块够大"之free_list
		for(i = size; i <= __MAX_BYTES; i += __ALIGN)
		{
			my_free_list = free_list + FREELIST_INDEX(i);
			p = *my_free_list;
			if(0 != p)
			{//free_list内尚有未用区块
			//调整free_list以释放未用区块
				*my_free_list = p->free_lists_link;
				start_free = (char*)p;
				end_free = start_free + i;
				//递归调用自己,为了修正nobjs
				return chunk_alloc(size,nobjs);
				//注意 任何残余零头终将被编入适当的free_list中备用
			}
		}
		end_free = 0;	//如果出现意外
		//调用第一级配置器，看看out_of_memory机制是否能够尽力
		start_free = (char*)malloc_alloc::allocate(bytes_to_get);
		//这会导致抛出异常(exception)，或内存不足的情况获得改善
		heap_size += bytes_to_get;
		end_free = start_free + bytes_to_get;
		//递归调用自己，为了修正nobjs
		return chunk_alloc(size,nobjs);
	 }
	}

}
