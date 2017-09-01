/*
3、质数对
【题目 述】给定一个正整数，编写程序计算有多少对质数的和等于输入的这个正整数，并输

出结果。输入 值小于 1000。如，输入为 10，程序应该输出结果为 2。(共有两对质数的和为 10，分别为(5,5)(3.7))
*/

#include <iostream>
#include <cmath>
using namespace std;

bool IsPrimer(int numbers)
{
	if(numbers <= 1)
		cout<<"numbers error"<<endl;
	if(numbers % 2 == 0)
		return false;
	for(int i = 3; i <= sqrt(numbers); ++i)
	{
		if(numbers%i == 0)
			return false;
	}
	return true;
}


int main()
{
	int sum  = 0;
	int num;
	cin>>num;
	for(int i = 3; i <= num/2; ++i)
	{
		if(IsPrimer(i) && IsPrimer(num-i))
			sum++;
	}
	cout<<sum<<endl;
	return 0;
}
