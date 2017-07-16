/*
	输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则打i1，2，3一直到最大的3位数即999
*/

//如果初看的话很容易认为题目非常简单，用一个循环喀什逐个打印就可以。但是仔细分析这个问题，我们就可以知道并么有规定n的范围。当输入 n很大的时候，我们求最大的n位数用long long都会溢出，也就是考虑大数问题

#include<iostream>
#include<string.h>
using namespace std;

void Print1ToMaxofNDigitsRecursively(char* number,int length,int index);
void PrintNumber(char* number);

//打印1到n位的所有十进制数
void Print1ToMaxofNDigits(int n)
{
	if(n < 0)
		return;
	char* number = new char[n+1];
	number[n] = '\0';

	for(int i = 0; i < 10; ++i)
	{
		number[0] = i + '0';
		Print1ToMaxofNDigitsRecursively(number,n,0);
	}
	delete []number;
}

//递归结束的条件是已经设置了最后一位
void Print1ToMaxofNDigitsRecursively(char* number,int length,int index)
{
	if(index == length -1)
	{
		PrintNumber(number);
		return;
	}

	for(int i = 0; i < 10; ++i)
	{
		number[index+1] = i  + '0';
		Print1ToMaxofNDigitsRecursively(number,length,index+1);
	}
}

//打印函数 不打印开头为0的数
void PrintNumber(char* number)
{
	bool isBeginning0 = true;
	int nLength = strlen(number);

	for(int i = 0; i < nLength; ++i)
	{
		if(isBeginning0 && number[i] != '0')
			isBeginning0 = false;
		
		if(!isBeginning0)
		{
			printf("%c",number[i]);
		}
	}
	printf("\t");

}

int main()
{
	cout<<"please input a number"<<endl;
	int n;
	cin>>n;
	Print1ToMaxofNDigits(n);
	return 0;
}
