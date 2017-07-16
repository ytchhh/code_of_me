#include<stdio.h>
#include<dlfcn.h>

int add(int ,int );

int main()
{	
	int sum = add(10,11);
	printf("sum = %d\n",sum);
	return 0;
}
