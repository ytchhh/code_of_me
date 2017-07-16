#include<stdio.h>
#include<dlfcn.h>
#include"add.c"

int main()
{	
	void *dl_handler = NULL;
	int (*func) (int ,int);

	char *error;
	int sum;
	dl_handler = dlopen("libadd.so",RTLD_LAZY);

	if(!dl_handler)
	{
		printf("open:%s\n",dlerror());
	}
	func = dlsym(dl_handler,"add");
	error = dlerror();

	if(error != NULL)
	{
		printf("find:%s\n",error);
		return 0;
	}

	sum = (*func)(10,11);
	printf("sum = %d\n",sum);
	dlclose(dl_handler);
	return 0;
}
