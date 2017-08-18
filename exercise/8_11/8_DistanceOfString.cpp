/*
	1、	数组中两个字符串的最小距离
	【题目】给定一个字符串数组ar,在给定两个字符串str1和str2,返回在ar中str1与str2的最小距离，如果str1或str2为null,或不在ar中，返回-1.
	【例如】
	ar =[“1”,”3”,”3”,”3”,”2”,”3”,”1”], str1=”1”, str2=”2” ,结果为2

*/

/*
	1.给定两个字符串出现的位置，会得到两个数组，假设为a和b。
	2.然后计算abs(a[i]-b[j])的最小值即可;
	第一步扫描一次字符串数组即可，第二步，如果简单的用两层循环来做，因为a和b的长度都有可能是n，那么用O(n*n)的时间。
	事实上，第二步可以在线性时间内解出来，这里有一个隐藏的特性，扫描原数组的时候得到的两个字符的位置数组，是有序的，比如数组[a,b,a,b,b,a]，那么a的位置数组为[0,2,5]，b的为[1,3,4]，假设我们比较到了位置2和位置3，我们是没有必要去比较位置2和4的；因为后者的距离肯定大于前者。
	可以得到这样的关系，当a[i]<b[j]的时候，增加a的坐标，当a>b的时候，增加b的坐标。这样就可以在O(N)的时间内完成。
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int min(int a,int b)
{
	return a > b ? b : a;
}

int DistanceOfString(vector<string>& ve,string str1,string str2)
{
	vector<int> ve1;
	vector<int> ve2;
	for(int i = 0; i < ve.size(); ++i)
	{
		if(ve[i] == str1)
			ve1.push_back(i);
		else if(ve[i] == str2)
			ve2.push_back(i);
	}
	int mindist = ve.size();
	for(int i=0,j=0; i<ve1.size()&&j<ve2.size(); )
	{
		int x = ve1[i];
		int y = ve2[j];
		mindist = min(mindist,abs(x-y));
		if(x < y)
			++i;
		else
			++j;
	}
	return mindist;
}

int main()
{
	vector<string> ve;
	ve.push_back("practice");
	ve.push_back("makes");
	ve.push_back("perfect");
	ve.push_back("coding");
	ve.push_back("makes");
//	ve.push_back("3");
//	ve.push_back("1");
	string str1("makes");
	string str2("coding");
	cout<<DistanceOfString(ve,str1,str2)<<endl;
	return 0;
}
