//	去掉字符串中连续出现K个0的子串

//给定一个字符串str和一个整数k,如果str中正好有连续的k个’0’字符出现时，把k个连续的’0’字符去除，返回处理后的字符串。
//【例如】str=”A00B”， k=2 ，结果为AB;
//        str=”A0000B000”, K=3, 结果为”A0000B”


#include <iostream>
#include <string>
using namespace std;

void deletestring(string& str,int k)
{
	if(str.size() == 0 || k <= 0)
		return ;
	int count = 0,j;
	for(int i = 0; i < str.size(); ++i)
	{
		count = 0;
		if(str[i] == '0')
		{
			j = i;
			while(str[i] == '0' && str[i] != '\0')
			{
				count++;
				i++;
			}
			if(count == k)
			{
				while(str[i] != '\0')
				{
					str[j] = str[i];
					++j;
					++i;
				}
				str[j] = '\0';
				cout<<str.c_str()<<endl;
				break;
			}
		}
	}
}


int main()
{
	string str("A0000B000");
	deletestring(str,3);
	cout<<str.c_str()<<endl;
	return 0;
}
