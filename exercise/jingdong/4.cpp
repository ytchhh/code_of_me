#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool Is_shen(string& temp)
{
	vector<int> ve;
	for(unsigned long long int i = 0; i < temp.size(); ++i)
	{
		int te = temp[i]-'0';
		ve.push_back(te);
	}
	if(ve.size() == 1)
		return false;
	int sum = 0;
	for(unsigned long long int i = 0; i < ve.size(); ++i)
	{
		sum += ve[i];
	}
	if(sum%2 != 0)
		return false;
	int target = sum/2;
	vector<int> count(sum+1, 0);
	count[0] = 1;

	for(int i = 0; i < ve.size(); ++i)
	{    
			int add = ve[i];
			for(int j = sum; j >= add; --j)
					count[j] += count[j-add];
	}
	return count[target];
}

int main()
{
	unsigned long long int a,b;
	cin>>a>>b;
	unsigned long long int sum = 0;
	for(; a <= b; ++a)
	{
		string temp = to_string(a);
		if(Is_shen(temp))
			sum++;
	}
	cout<<sum<<endl;
	return 0;
}
