/*
	实现函数double Power(double base,int exponent),求base的exponent次方。不得使用库函数，同时不需要考虑大数问题
*/

#include<iostream>
using namespace std;

bool g_InvaildInput = false;

double PowerWithUnsignedExponent(double base,unsigned int exponent)
//用递归来解决大数的模运算
{
	if(exponent == 0)
		return 1;
	if(exponent == 1)
		return base;

	double result = PowerWithUnsignedExponent(base,exponent>>1);
	//右移一位代表的运算和处以2是等价的，但是右移运算符的效率要比除法的高
	result *= result;
	//判断是否为偶数
	if(exponent & 0x1 == 1)
		result *= base;
	return result;
}

bool equal(double num1,double num2)
//单精度小数的比较是和0.0000001比较才行
{
	if( ((num1 - num2) > 0.0000001) && ((num1 - num2) < 0.0000001) )
		return true;
	else
		return false;
}

double Power(double base,int exponent)
{
	g_InvaildInput = false;
	
	if(equal(base,0.0) && exponent < 0)
	{
		g_InvaildInput = true;
		return 0.0;
	}
	
	unsigned int absExponent = (unsigned int) (exponent);
	if(exponent < 0)
		absExponent = (unsigned int)(-exponent);
	
	double result = PowerWithUnsignedExponent(base,absExponent);
	if(exponent < 0)
		result = 1.0 / result;
	return result;
}

int main()
{
	cout<<"please input two number"<<endl;
	int m,n;
	cin>>m>>n;
	cout<<"Power is "<<Power(m,n)<<endl;
	return 0;
}
