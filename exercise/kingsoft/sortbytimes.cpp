/*
	给定一个字符串S，求所有长度小于3的子串出现的次数，输出结果按出现次数从大到小排序，如果次数相同，按字典序排序。比如，给定字符串"abcdab"，输出结果为
	a 2
	ab 2
	b 2
	abc 1
	bc 1
	bcd 1
	c 1
	cd 1
	cda 1
	d 1
	da 1
	dab 1
*/

#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<pair<string,int>>& calculate3Gram(string s)
{
	if(s.size() != 0)
	{
		map<string,int> mp;
		
		for(int i = 0; s[i] != '\0'; ++i)
		{
			map<string,int>::iterator it;
			string temp(1,s[i]);
			if(s[i] != '\0')
			{
				it = mp.find(temp);
				if(it == mp.end())
					mp[temp] = 1;
				else
					mp[temp]++;
			}
			if(s[i+1] != '\0')
			{
				temp += s[i+1];
				it = mp.find(temp);
				if(it == mp.end())
					mp[temp] = 1;
				else
					mp[temp]++;
			}
			if(s[i+2] != '\0')
			{
				temp += s[i+2];
				it = mp.find(temp);
				if(it == mp.find(temp))
					mp[temp] = 1;
				else
					mp[temp]++;
			}
		}
		map<string,int>::iterator it = mp.begin();
		int i = 0;
		for(; it != mp.end(); ++it)
		{
			cout<<it->first<<" "<<it->second<<endl;
			i++;
		}
		vector<pair<string,int>> *ve = new vector<pair<string,int>>[i];
		for(it = mp.begin(); it != mp.end(); ++it)
		{
			it = mp.begin();
			int max = it->second;
			map<string,int>::iterator it2 = mp.begin(),it3 = it;
			while(it2 != mp.end())
			{
				if(max < it2->second)
					it3 = it2;
				++it2;
			}
			pair<string,int> value(it3->first,it3->second);
			mp.erase(it3);
			ve->push_back(value);
		}
		cout<<"----------------"<<endl;
		return *ve;
	}
}


int main()
{
	string str("abcdab");
	vector<pair<string,int>> ve;
	ve = calculate3Gram(str);
	for(int i = 0; i < ve.size(); ++i)
		cout<<ve[i].first<<" "<<ve[i].second<<endl;

}
