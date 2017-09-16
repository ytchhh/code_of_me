#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string admin,passwd;
	while(cin >> admin >> passwd)
	{
		int length = passwd.length();
		int count = 0;
		bool num = false;
		bool xiao = false;
		bool da = false;
		for(int i = 0; i < passwd.length(); ++i)
		{
			if(passwd[i] >= '0' && passwd[i] <= '9')
			{
				count++;
				num = true;
				break;
			}
		}
		for(int i = 0; i < passwd.length(); ++i)
		{
			if(passwd[i] >= 'a' && passwd[i] <= 'z')
			{
				count++;
				xiao = true;
				break;
			}
		}
		for(int i = 0; i < passwd.length(); ++i)
		{
			if(passwd[i] >= 'A' && passwd[i] <= 'Z')
			{
				count++;
				da = true;
				break;
			}
		}
		string temp = passwd;
		reverse(temp.begin(), temp.end());
		if(length < 8 || count == 1 || (admin == passwd || admin == temp))
		{
			cout << 0 << endl;
		}
		else if(length == 8 && count == 2 && (num&&xiao || num&&da))
		{
			cout << 1 << endl;
		}
		else if(length >= 8 && count == 2 && (!(num&&xiao) || !(num&&da)) )
		{
			cout << 2 << endl;
		}
		else if(length >= 8 && count >=3)
		{
			cout << 3 << endl;
		}
	}
	
	return 0;
}
