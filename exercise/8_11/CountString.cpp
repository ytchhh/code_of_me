/*
	1、	字符串的统计
	【题目】给定一个字符串str, 返回str的统计字符串
	【例如】”aaabbadddffc”的统计字符串为”a_3_b_2_a_1_d_3_f_2_c_1”

*/

#include <iostream>
#include <string>
using namespace std;

string CountString(string str)
{
	string result = "";
	char pre = str[0];
	string s("_");
	int count = 0;
	for(int i = 0; str[i] != '\0'; ++i)
	{
		if(str[i] == pre)
		{
			count++;
		}
		else
		{
			char a[50];
			sprintf(a,"%d",count);
			result += pre + s + a + s;
			count = 1;
			pre = str[i];
		}
	}
	return result;
}

int main()
{
	string result = CountString("aaabbadddffc");
	cout<<"CountString(aaabbadddffc)"<<result<<endl;
	return 0;
}
