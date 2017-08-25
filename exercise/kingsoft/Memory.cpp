/*
	设计一个内存池，支持1k以下内存的分配操作
*/

union obj
{
	union obj* free_list_link;
	char client_data[1];
};

enum {__ALIGN = 64};
enum {__MAX_BYTES = 1024};
enum {__NFREELISTS = __MAX_BYTES/__ALIGN}:

obj* free_list[__NFREELISTS] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

size_t ROUND_UP(size_t bytes)
{
	return ( ((bytes) + __ALIGN-1) & ~(__ALIGN-1) );
}

size_t FREELIST_INDEX(size_t bytes)
{
	return ( ((bytes) + __ALIGN-1)/__ALIGN -1 );
}

void* refill(size_t n);

void* allocate(size_t n)
{
	obj* volatile *my_free_list;
	obj* result;
	if(n > 1024)
	{
		return malloc(n);
	}
	my_free_list = free_list + FREELIST_INDEX(n);
	result = *my_free_list;
	if(result == 0)
	{
		void *r = refill(ROUND_UP(n));
		return r;
	}
	*my_free_list = result->free_list_link;
	return result;
}

void refill(size_t n)
{
	int nobjs = 20;
	char* chunk
}
