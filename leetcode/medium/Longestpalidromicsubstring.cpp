/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"

*/

#include <iostream>
#include <string>
using namespace std;

string LongestSubstring(string& s)
{
	if(s.length() == 0)
		return "";
	bool exist[s.length()][s.length()] = {false};
	string res;
	int maxlen = 0;
	for(int i = s.length()-1; i >= 0; --i)
	{
		for(int j = i; j < s.length(); ++j)
		{
			if(s[i] == s[j] && (j-i<=2 || exist[i+1][j-1]))
			{
				exist[i][j] = true;
				if(maxlen < j-i+1)
				{
					maxlen = j-i+1;
					res = s.substr(i,maxlen);
				}
			}
		}
	}
	return res;
}

int main()
{
	string str("abcbaty");
	cout << LongestSubstring(str) << endl;
	return 0;
}
