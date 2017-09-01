#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
using namespace std;

void LongestSubstring(string& s)
{
	assert(s.size() != 0);
	int n = s.size();
	int i, j,longest,start;
	for (i = 0; i < n; ++i)
	{
		bool exist[10] = {false};
		exist[s[i]-'0'] = true;
		for (j = i + 1; j < n; ++j)
		{
			if (exist[s[j]-'0'] == false)
			{
				exist[s[j]-'0'] = true;
			}
			else
			{
				if (j - i > longest)
				{
					longest = j - i;
					start = i;
				}
				break;
			}
		}
		if ((j == n) && (j - i > longest))
		{
			longest = j - i;
			start = i;
		}
	}
	cout<<start<<" "<<longest<<endl;
	string temp = s.substr(start,longest);
	cout<<temp<<endl;
}


int main()
{
		string s("120135435");
		LongestSubstring(s);
		return 0;
}
