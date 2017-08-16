/*
	1、	判断字符串数组中是否所有的字符都只出现过一次
	【例如】str[] = {‘a,’’b’,’c’}   结果为true
	        str[] = {‘a’,’b’,’a’}    结果为false

*/

#include <iostream>
#include <string>
using namespace std;


bool Is_TimeIs1(string str)
{
	if(str.size() == 0)
		return false;
	int buffer[256] = {0};
	for(int i = 0; str[i] != '\0'; ++i)
	{
		if(buffer[str[i]] != 0)
			return false;
		else
			buffer[str[i]]++;
	}
	return true;
}

int main()
{
	if(Is_TimeIs1("aba"))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	return 0;
}
