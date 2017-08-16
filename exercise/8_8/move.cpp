#if 1
#include<string>
#include<iostream>

using namespace std;

string move(string str)
{
		if(str.length() == 1)
				return str;
		int i,k = str.length()-1;
		for(i = k; i >= 0; --i)
		{
				if(str[i] >= 'A' && str[i] <= 'Z')
				{
						if(str[k] >= 'a' && str[k] <= 'z')
						{
								char temp;
								temp = str[i];
								str[i] = str[k];
								str[k] = temp;
						}
						--k;
				}
		}
		return str;
}

int main()
{
		string s;
		while(cin>>s)
		{
				cout<<move(s)<<endl;
		}
		return 0;
}
#endif

#if 0

#include <string>
#include <iostream>
using namespace std;


int	main()
{
	string s;
	while(cin >> s)
	{
		if(s.length() >= 1 && s.length() <= 1000)
			for(int i = 0; i < s.length(); ++i)
				if(s[i] >= 'a' && s[i] <= 'z')
					cout<<s[i];
			for(int i = 0; i < s.length(); ++i)
				if(s[i] >= 'A' && s[i] <= 'Z')
					cout<<s[i];
			cout<<endl;
	}
	return 0;
}
#endif
