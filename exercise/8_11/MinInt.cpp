/*
   请编写一个函数func,输入一个最小的正整数m（m>9,即m至少包含两位数），使得m的各位乘积等于n，例如输入36，输出49；输入100，输出455，如果对于某个n不存在着这样的m，请输出-1，
 */


#include <stdio.h>
#include <iostream>
using namespace std;


int func(int n)
{
		if(n < 0)
				return -1;
		int sum = n;
		int q = 9,p = 0;
		int i = 2;
		while(sum > 9*q)
		{
				++i;
				q *= 9;
		}
		int a[i];
		int r = i;
		while(i)
		{
				for(int j = 9; j > 0; --j)
				{
						if(sum%j == 0)
						{
								a[p++] = j;
								--i;
								sum /= j;
								break;
						}
				}
		}
		sum = 0;
		for(; r > 0; --r)
			sum = sum*10 + a[r-1];
		return sum;
}

int main()
{
	cout<<"-------:"<<func(100)<<endl;
	return 0;
}
