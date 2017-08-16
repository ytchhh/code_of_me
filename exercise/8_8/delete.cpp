/*
   给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
   输出需要删除的字符个数
 */


#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;


//先求s的反串reverse，然后求他们的最长的公共子序列，要删除的字符个数就能知道
//时间复杂度O(N^2)

int getRemoveNumber(string &s1)
{
		string s2(s1);
		reverse(s2.begin(),s2.end());
		int len=s1.length();
		int temp[len+1][len+1];
		int i,j;
		memset(temp,0,sizeof(temp));
		for(i=0;i<len;++i)
		{
				for(j=0;j<len;++j)
				{
						if(s1[i]==s2[j])
								temp[i+1][j+1]=temp[i][j]+1;
						else temp[i+1][j+1]=max(temp[i][j+1],temp[i+1][j]);
				}
		}
		return len-temp[len][len];
}

int main()
{
		string s;
		while(cin>>s)
		{
				cout<<getRemoveNumber(s)<<endl;
		}
		return 0;
}

