给定一个字符串S和有效单词的字典D，请确定可以插入到S中的最小空格数，使得最终的字符串完全由D中的有效单词组成，并输出解。
如果没有解则应该输出n/a
例如
输入
S = "ilikealibaba"
D = ["i", "like", "ali", "liba", "baba", "alibaba"]
Example Output:
输出
"i like alibaba"
解释：
字符串S可能被字典D这样拆分
"i like ali baba"
"i like alibaba"
很显然，第二个查分结果是空格数最少的解。

/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#define MAX_DICT_LEN 255
#define MAX_STR 255

typedef struct simple_str 
{
const char * str;
int len;
} simple_str_t;


bool IsEqual(char* str1,char* str2)
{
if(strlen(str1) != strlen(str2))
return false;
int i = 0;
while(str1[i++] == str2[i++])
;
if(i == strlen(str1))
return true;
else
return false;
}

void mincut(simple_str_t* str, simple_str_t* dict, int dict_len) 
{
for(int i = 0; i < str->len; ++i)
{

for(int j = 0; j )
}
}


int main(int argc, const char * argv[]) 
{
char strS[MAX_STR];
char dictStr[MAX_STR];
int nDict;
simple_str_t dict[MAX_DICT_LEN];
simple_str_t srcStr;

scanf("%s", strS);
scanf("%d", &nDict);

srcStr.str = strdup(strS);
srcStr.len = strlen(strS);

for (int i = 0; i < nDict; i++)
{
scanf("%s", strS);
dict[i].str = strdup(strS);
dict[i].len = strlen(strS);
}

mincut(&srcStr, dict, nDict);

return 0;
}
 */

#include <iostream>
#include <string>
#include <set>

using namespace std;

string pincou(string& str,int start,int end)
{
	string temp;
	for(int i = start; i <= end; ++start)
		temp += str[i];
	return temp;
}

void mincut(const string& str, const set<string>& dict)
{
	int i = 0,j;
	string newstring;
	for(int i = 0; i < dict.size(); ++i)
	{
		int n = dict[i].size();
		j = n;
		string temp = pincou(str,i,j);
		if(temp == dict[i])
			newstring += temp + " ";
	}
}


int main(int argc, const char * argv[])
{
		string strS;
		string dictStr;
		int nDict;
		set<string> dict;

		cin>>strS;
		cin>>nDict;
		for (int i = 0; i < nDict; i++)
		{
				cin>>dictStr;
				dict.insert(dictStr);
		}
		mincut(strS, dict);

		return 0;
}
