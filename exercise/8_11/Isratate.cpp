/*
   1、	判断两个字符串是否为旋转词
   【题目】如果一个字符串str, 把字符串str前面的部分挪到后面形成的字符串叫做str的旋转词，比如str=”12345”,str的旋转词有”12345”,”23451”,”34512”,”45123”,”51234”,给定两个字符串a和b,请判断a 和b是否互为旋转词。
   【要求】解法时间复杂度0(N)
 */

#include <iostream>
#include <string>
using namespace std;

bool IsRatate(string str1,string str2)
{
		if(str1.size()<0 || str2.size()<0 || str2.size() != str2.size())
				return false;
		string s = str1 + str2;
		int ret = s.find(str2);
		return ret != -1;
}

int main()
{
		string str1 = "12345";
		string str2 = "23451";
		if(IsRatate(str1,str2) == true)
				cout<<"Ratate"<<endl;
		else
				cout<<"Not Ratate"<<endl;
		return 0;
}
