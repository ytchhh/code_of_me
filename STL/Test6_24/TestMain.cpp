#include"./stl_alloc.h"

//采用一级空间配置器的做法
/*
void Out_of_Memory()
{
	cout<<"My Out Of Memory"<<endl;
	exit(1);
}

int main()
{
	__malloc_alloc_template<0>::set_new_handler(Out_of_Memory);
	int *p = (int*)__malloc_alloc_template<0>::allocate(sizeof(int)*536870911);
	__malloc_alloc_template<0>::deallocate(p,sizeof(int));
	return 0;
}
*/

int main()
{	
	int *p = (int*)__default_alloc_template<0,0>::allocate(sizeof(int));
	int *p1 = (int*)__default_alloc_template<0,0>::allocate(sizeof(int));
	return 0;
}
