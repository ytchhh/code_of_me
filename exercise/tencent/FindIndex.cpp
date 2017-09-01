/*
	假定一种编码的编码范围是a ~ y的25个字母，从1位到4位的编码，如果我们把该编码按字典序排序，形成一个数组如下： a, aa, aaa, aaaa, aaab, aaac, … …, b, ba, baa, baaa, baab, baac … …, yyyw, yyyx, yyyy 其中a的Index为0，aa的Index为1，aaa的Index为2，以此类推。 编写一个函数，输入是任意一个编码，输出这个编码对应的Index.

	输入描述:

	输入一个待编码的字符串,字符串长度小于等于100.

	输出描述:

	输出这个编码的index

	示例1

	输入

	baca

	输出

	16331

	思路：两层for循环，一层编码长度，一层当前位数，找规律发现该编码每次加n*25^j，n是当前位字母编码是第几个，j是当前位数的第几位。
*/


#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main()
{
	string s;
	cin>>s;
	int len = s.length();
	int index = 0,i,j;
	for(i = 0; i < len; ++i,++index)
	{
		int n = s[i] - 'a';
		for(j = 0; j <4-i; ++j)
		{
			index += n*pow(25,j);
		}
	}
	cout<<index-1<<endl;
	cout<<sizeof(A)<<endl;
	return 0;
}
