/*
	字符串A和B的最长公共单词
*/

#include <string.h>

#include <iostream>
#include <string>
using namespace std;

void LongestCommon_Substring(char *str1,char *str2,char *result)
{
	if(str1 == NULL || str2 == NULL)
		return;
	int maxlength = 0;
	int curpositin = -1;
	for(int i = 0; i < strlen(str1); ++i)
	{
		for(int j = 0; j < strlen(str2); ++j)
		{
			if(str1[i] == str2[j])
			{
				for(int k = 1; str1[i+k]==str2[j+k]&&str1[i+k]!='\0'; ++k)
				{
					if(k > maxlength)
					{
						maxlength = k;
						curpositin = i;
					}
				}
			}
		}
	}
	if(curpositin == -1)
		return;
	else
	{
		memcpy(result,str1+curpositin,maxlength);
		result[maxlength] = '\0';
	}
}

int main()
{
	char result[512] = {'\0'};;
	LongestCommon_Substring("zhangligou","gligzhangligu",result);
	cout<<result<<endl;
	return 0;
}
