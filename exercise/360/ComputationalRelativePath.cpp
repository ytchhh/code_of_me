
/*
	在写一个函数，根据两个文件的绝对路径算出相对路径。如a="/qihoo/app/a/b/c/d/new.c",
	b="qihoo/app/1/2/test.c"，那么b相对于a的相对路径是"../../../../../1/2/test.c"
*/

#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

void ComputationalRelativePath(char *str1,char *str2)
{
	assert(str1 != NULL && str2 != NULL);
	int i;
	char *p = NULL,*q = NULL;
	char temp[128] = {'\0'};
	for(i = 0; i < strlen(str1); ++i)
	{
		if(str1[i] != str2[i])
		{
			p = str1+i;
			q = str2+i;
			break;
		}
	}
	while(str1[i++] != '\0')
	{
		if(str1[i] == '/')
			strcat(temp,"../");
	}
	strcat(temp,q);
	cout<<temp<<endl;
}

int main()
{
	char str1[] = "/qihoo/app/a/b/c/d/new.c";
	char str2[] = "/qihoo/app/1/2/test.c";
	ComputationalRelativePath(str1,str2);
	return 0;
}
