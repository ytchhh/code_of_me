/*
	1、	字符串中数字子串的求和
	【题目】给定一个字符串str,求其中全部数字串所代表的数组之和
	【要求】a>忽略小数点字符，如”A.1.3”其中包含两个数字1和3
	b>如果紧贴数字子串的左侧出现字符”-”，当连续出现的数量为奇数时，则数字视为负，连续出现的数量为偶数时，则视为正，如，”A-1BC- -12”，其中包含数字为-1和12
	【例如】str=”A1CD2E33” 结果为36
	        Str=”A-1B- -2C- -D6E” 结果为7
*/

#include <iostream>
#include <string>
using namespace std;

bool IsNumber(char a)
{
	if(a >= '0' && a <= '9')
		return true;
	return false;
}

int SumOfNum(string str)
{
	if(str.size() == 0)
		return -1;
	int sum = 0;
	int result = 0;
	bool flag = true;
	int cur;
	for(int i = 0; i < str.size(); ++i)
	{
		if(IsNumber(str[i]))
		{
			cur = str[i] - '0';
			sum = sum*10 + (flag ? cur : -cur);
		}
		else
		{
			result += sum;
			sum = 0;
			if(str[i] == '-')
			{
				if(i-1 > 0 && str[i-1] == '-')
					flag = true;
				else
					flag = false;
			}
			else
				flag = true;
		}
	}
	result += sum;
	return result;
}

int main()
{
	string s1("A1----4FG-12345Fg");
	cout<<"sum  = "<<SumOfNum(s1)<<endl;
}
