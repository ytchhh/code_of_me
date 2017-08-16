/*
1、	判断两个字符串是否为变形词
【题目】给定两个字符串s1,s2, 如果s1和s2中出现的字符种类和字符次数一样多，则s1和s2互为变形词，实现函数判断两个字符串是否为变形次。
【例如】s1=”123”,s 2=”321” ,return true;
        s1=”123”,s2=”2113”, return false;
*/

#include <iostream>
#include <string>
using namespace std;

bool IsMetamorphic(string s1,string s2)
{
	if(s1.size() == 0 || s2.size() == 0 || s1.size() != s2.size())
		return false;
	int array[255] = {0};
	for(int i = 0; i < s1.size(); ++i)
		array[s1[i]]++;
	for(int i = 0; i < s2.size(); ++i)
		array[s2[i]]--;
	for(int i = 0; i < 255; ++i)
		if(array[i] != 0)
			return false;
	return true;
}

int main()
{
	string s1("123");
	string s2("321");
	if(IsMetamorphic(s1,s2))
		cout<<"true\n"<<endl;
	else
		cout<<"false\n"<<endl;
	return 0;
}
