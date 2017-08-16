/*
   Given an array of integers, return indices of the two numbers such that they add up to a specific target.

   You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
 */

/*
#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) 
{
	int i = 0;
	int j = nums.size()-1;
	vector<int> *ve = new vector<int>;
	for(; i < j; ++i,--j)
	{
		int k = i;
		while(k < j)
		{
			if(nums[k]+nums[j] == target)
			{
				ve->push_back(k);
				ve->push_back(j);
				return *ve;
			}
			++k;
		}
		k = j;
		while(k > i)
		{
			if(nums[k]+nums[i] == target)
			{
				ve->push_back(i);
				ve->push_back(k);
				return *ve;
			}
			--k;
		}
	}
}

int main()
{
	vector<int> ve;
	ve.push_back(-3);
	ve.push_back(4);
	ve.push_back(3);
	ve.push_back(90);
	int target = 0;
	vector<int> v1 = twoSum(ve,target);
	for(int i = 0; i < v1.size(); ++i)
	{
		cout<<v1[i]<<endl;
	}
	return 0;
}
*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums,int target)
{
	vector<int> *ve = new vector<int>;
	map<int,int> mp;
	for(int i = 0; i < nums.size(); ++i)
	{
	//扫一遍数组，一边扫一边存。
		int cur = nums[i];
		//差值就是在没有找到之后添加到map里面去的。
		int toFind = target - cur;
		//如果发现之前需要这个差值，那就找index。
		if(mp.find(cur) != mp.end())
		{
			map<int,int>::iterator it = mp.find(cur);
			ve->push_back(it->second);
			ve->push_back(i);
			return *ve;
		}
		//如果没有找到的话，就插入到map里面去。
		else
		{
			pair<int,int> value(toFind,i);
			mp.insert(value);
		}
	}
}

int main()
{
	
	vector<int> ve;
	ve.push_back(-3);
	ve.push_back(4);
	ve.push_back(3);
	ve.push_back(90);
	int target = 0;
	vector<int> v1 = twoSum(ve,target);
	for(int i = 0; i < v1.size(); ++i)
	{
		cout<<v1[i]<<endl;
	}
	return 0;
}
