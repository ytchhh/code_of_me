#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int n;
	cin>>n;
	vector<string> ve;
	for(int i = 0; i < n; ++i)
	{
		string str;
		cin>>str;
		ve.push_back(str);
	}
	for(int i = 0; i < n; ++i)
	{
		int sum = 0,countd,counti;
		string temp = ve[i];
		for(int j = 0; j < temp.size(); ++j)
		{
			countd = 0;
			counti = 0;
			if(temp[j] == 'j')
			{
				for(int k = 0; k < j; ++k)
				{
					if(temp[k] == 'd')
						countd++;
				}
				for(int m = j+1; m <= temp.size(); ++m)
				{
					if(temp[m] == 'i')
						counti++;
				}
				sum += countd*counti;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
