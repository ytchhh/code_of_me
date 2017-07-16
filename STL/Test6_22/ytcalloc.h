#ifndef _YTCALLOC_H
#define	_YTCALLOC_H

#include<new>
#include<cstddef>
#include<climits>
#include<cstdlib>
#include<string.h>
#include<iostream>
using namespace std;

void outofmem()
{
	cerr<<"Unable to satisfy requestment"<<endl;
	abort();
}

namespace ytc
{
template<class T>
inline T* _allocate(ptrdiff_t size,T*)	//_打头的函数都是一些在内部所调用的函数
{
	cout<<typeid(T).name<<endl;
	set_new_handler(outofmem);		//内存分配不足时调用的函数
	T* tmp = (T*)(::operator new ((size_t)(size * sizeof(T))));
	if(tmp == 0)
	{
		cerr<<"out of memory!"<<endl;
		exit(1);
	}
	return tmp;
}

template<class T>
inline void _deallocate(T *buffer)		//析构
{
	::operator delete(buffer);
}

template<class T1,class T2>
inline void _construct(T1 *p,const T2& value)	//构造函数
{
	new(p) T1(value);
}

template<class T>
inline void _destroy(T *ptr)
{
	ptr->~T();
}

template<class T>
class allocator
{
public:
	typedef T 			value_type;
	typedef T* 			pointer;
	typedef const T* 	const_pointer;
	typedef T&			reference;
	typedef const T&	const_reference;
	typedef size_t 		size_type;
	typedef ptrdiff_t 	difference_type;

	//rebind allocator of type U
	template<class U>
	struct rebind
	{
		typedef allocator<U> other;
	};

	pointer allocate(size_type n,const void* hint = 0)
	{
		return _allocate((difference_type)n,(pointer)0);
	}

	void deallocate(pointer p,size_type n)
	{
		_deallocate(p);
	}

	void construct(pointer p,const T& value)
	{
		_construct(p,value);
	}

	pointer address(reference p)
	{
		_destroy(p);
	}

	const_pointer const_address(const_reference x)
	{
		return (const_pointer)&x;
	}

	size_type max_size() const
	{
		return size_type(UINT_MAX/sizeof(T));
	}
};

}	//end of ytc

class String
{
public:
	String(const char* str = "")
	{
		data = new char[strlen(str) + 1];
		strcpy(data,str);
	}
	~String()
	{
		delete []data;
		data = NULL;
	}
private:
	char *data;
};

#endif



