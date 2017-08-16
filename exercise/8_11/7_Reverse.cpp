/*
	1、	翻转字符串
	【题目】给定一个字符串类型的数组ar, q请在单词间做逆序调整，只要做到单词顺序逆序即可，对空格的位置没有特殊要求
	【例如】str=”dog loves pig”, 调整后”pig loves dog”

*/

#include <iostream>
#include <string>
using namespace std;

string ReverseString(string str)
{
	int length = str.size();
	int i,j;
	char temp;
	for(i = 0,j = length-1; i < j; ++i,--j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	return str;
}

int main()
{
	string str("dog loves pig"),str1;
	str = ReverseString(str);
	for(int i = 0; str[i] != '\0'; ++i)
	{
		char temp[str.size()] = {'\0'};
		int j = 0;
		while(str[i] != ' ' && str[i] != '\0')
		{
			temp[j++] = str[i++];
		}
		str1 = ReverseString(temp);
		cout<<str1<<" ";
	}
	cout<<'\n';
	return 0;
}
