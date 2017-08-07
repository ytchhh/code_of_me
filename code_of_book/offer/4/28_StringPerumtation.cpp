/*
	输入一个字符串，打印出该字符串中字符的所有排列。例如输入字符串abc，则打印出由字符a,b,c所能排列出来的所有字符串abc，acb,bac,bca,cab,和cba。
	第一部分为它的第一个字符，第二部分是后面的字符。
	我们求整个字符串的排列，可以看出两步，首先求所有可能出现在第一个位置的字符，即把第一个字符和后面所有的字符交换。第二部固定第一个字符，求后面所有字符的排列。这个时候我们仍把后面的所有字符分成两部分；后面字符的第一个字符，以及这个字符之后的所有字符。
*/

#if 0
//递归实现
#include <assert.h>

#include <iostream>
using namespace std;

void swap(char& a,char& b)
{
	char temp;
	temp = a;
	a = b;
	b = temp;
}

void permutation(char* str,char* begin)
{
	assert(str && begin);
	if(*begin == '\0')
		printf("%s\n",str);
	else
	{
		for(char *ch = begin; *ch != '\0'; ++ch)
		{
			swap(*begin,*ch);
			permutation(str,begin+1);
			swap(*begin,*ch);
		}
	}
}

int main()
{
	char str[] = "abc";
	permutation(str,str);
	return 0;
}
#endif

#if 0

#include <stdio.h>
#include <string.h>
#include <assert.h>
void swap(char& a,char& b)
{
	char temp;
	temp = a;
	a = b;
	b = temp;
}

//k表示当前取到第几个数，m表示有多少个数
void permutation(char *str,int k,int m)
{
	assert(str);
	if(k == m)
	{
		static int num = 1;
		printf("第%d个排列\t%s\n",num++,str);
	}
	else
	{
		for(int i = k; i <= m; ++i)
		{
			swap(*(str+k),*(str+i));
			permutation(str,k+1,m);
			swap(*(str+k),*(str+i));
		}
	}
}

int main()
{
	char str[] = "abc";
	permutation(str,0,strlen(str)-1);
	return 0;
}
#endif

#if 1

#include <assert.h>

#include <iostream>
using namespace std;
void swap(char& a,char& b)
{
	char temp;
	temp = a;
	a = b;
	b = temp;
}

bool IsSwap(char* begin,char* end)
{
	char *p;
	for(p = begin; p < end; ++p)
	{
		if(*p == *end)
			return false;
	}
	return true;
}

void permutation(char *str,char *begin)
{
	assert(str);
	if(*begin == '\0')
	{
		static int num = 1;
		printf("第%d个全排列%s\n",num++,str);
	}
	else
	{
		for(char *ch = begin; *ch != '\0'; ++ch)
		{
			if(IsSwap(begin,ch))
			{
				swap(*begin,*ch);
				permutation(str,begin+1);
				swap(*begin,*ch);
			}
		}
	}
}

int main()
{
	char str[] = "abcc";
	permutation(str,str);
	return 0;
}
#endif
