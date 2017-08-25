/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
#include <assert.h>

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstring(string s)
{
	assert(s.size() != 0);
	int i = 0,j = 0,n = s.size();
	bool exist[256] = {false};
	int maxlength = 0;
	while(j < n)
	{
		if(exist[s[j]])
		{
			maxlength = max(maxlength,j-i);
			while(s[i] != s[j])
			{
				exist[s[i]] = false;
				++i;
			}
			++i;
			++j;
		}
		else
		{
			exist[s[j]] = true;
			++j;
		}
	}
	maxlength = max(maxlength,j-i);
	return maxlength;
}

int main()
{
	string str("pwwkew");
	cout<<lengthOfLongestSubstring(str)<<endl;
	return 0;
}
