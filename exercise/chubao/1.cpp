/*

 */


#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
		int n;
		cin>>n;
		vector<string> ve;
		for(int i = 0; i < n; ++i)
		{
				string temp;
				cin>>temp;
				ve.push_back(temp);
		}
		int m;
		cin>>m;
		vector<string> ve1;
		for(int i = 0; i < m; ++i)
		{
				string temp;
				cin>>temp;
				ve1.push_back(temp);
		}
		for(int i = 0; i < m; ++i)
		{
				int count = 0;
				for(int j = 0; j < n; ++j)
				{
						size_t fi = ve[j].find(ve1[i]);
						if(fi != ve[j].npos)
						{
								count++;
						}
				}
				cout<<count<<endl;
		}
		return 0;
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void find(vector<string>& ve,vector<string>& ve1)
{
		for(int i = 0; i < ve1.size(); ++i)
		{
				int count = 0;
				for(int j = 0; j < ve.size(); ++j)
				{
						size_t fi = ve[j].find(ve1[i]);
						if(fi != ve[j].npos)
						{
								count++;
						}
				}
				cout<<count<<endl;
		}
}

int main()
{
		int n;

		while(cin>>n)
		{
				vector<string> ve;
				for(int i = 0; i < n; ++i)
				{
						string temp;
						cin>>temp;
						ve.push_back(temp);
				}
				int m;
				cin>>m;
				vector<string> ve1;
				for(int i = 0; i < m; ++i)
				{
						string temp;
						cin>>temp;
						ve1.push_back(temp);
				}
				find(ve,ve1);
		}
		return 0;
}
