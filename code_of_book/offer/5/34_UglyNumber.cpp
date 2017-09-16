
	丑数
	题目：我们把只包含因子2、3、5的数称为丑数。求按从大到小的顺序的第1500个丑数。例如6、8是丑数，但14不是，因为他包含因子7.习惯上我们把1当做第一个丑数。
*/

/*
	根据丑数的定义，丑数应该是另一个丑数乘以2、3、或者5的结果。因此我们可以创建一个数组，
里面的数乘以2、3、5的结果（1除外）。因此我们可以创建一个数组，里面的数字是
排好序的丑数，每一个丑数都是前面的丑数乘以2、3、5得到的。
*/

#include <iostream>
using namespace std;

int Min(int number1,int number2,int number3)
{
	int min = (number1 < number2) ? number1 : number2;
	min = (min < number3) ? min : number3;
	return min;
}

int GetUglyNumber_Soution2(int index)
{
	if(index <= 0)
		return 0;
	
	int *pUglyNumbers = new int[index];
	pUglyNumbers[0] = 1;
	int nextUglyNumber = 1;

	int *pMultiply2 = pUglyNumbers;
	int *pMultiply3 = pUglyNumbers;
	int *pMultiply5 = pUglyNumbers;

	while(nextUglyNumber < index)
	{
		int min = Min(*pMultiply2,*pMultiply3,*pMultiply5);
		pUglyNumbers[nextUglyNumber] = min;
		while(*pMultiply2*2 <= pUglyNumbers[nextUglyNumber])
			++pMultiply2;
		while(*pMultiply3*3 <= pUglyNumbers[nextUglyNumber])
			++pMultiply3;
		while(*pMultiply5*5 <= pUglyNumbers[nextUglyNumber])
			++pMultiply5;
		++nextUglyNumber;
	}
	int ugly = pUglyNumbers[index-1];
	delete[] pUglyNumbers;
	return ugly;
}

int main()
{
	cout<<" = "<<GetUglyNumber_Soution2(2)<<endl;
	return 0;
}
