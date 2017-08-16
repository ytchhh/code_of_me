/*
	输入一个整型数组，数组里有正数也有负数。数组中一个或连续的多个整数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为O(n)。
*/

#include <iostream>

using namespace std;

int FindCreatestSumOfSubarray(int *pData,int nLength)
{
	if(pData == NULL || nLength <= 0)
		return 0;
	
	int CurSum = 0;
	int GreateSum = 0;
	for(int i = 0; i < nLength; ++i)
	{
		if(CurSum <= 0)
			CurSum = pData[i];
		else
			CurSum += pData[i];
		if(CurSum > GreateSum)
			GreateSum = CurSum;
	}
	return GreateSum;
}

int main()
{
	int array[] = {1,-2,3,10,-4,7,2,-5};
	cout<<FindCreatestSumOfSubarray(array,sizeof(array)/sizeof(array[0]))<<"---"<<endl;
	return 0;
}
