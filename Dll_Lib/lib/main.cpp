#include<stdio.h>
#include"add.h"
#include"sub.h"

int main()
{
	int a,b;
	a = add(3,4);
	b = sub(9,6);
	printf("a = %d,b = %d\n",a,b);
	return 0;
}
