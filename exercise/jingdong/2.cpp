/*
{A}+{B}。
注:同一个集合中不会有两个相同的元素。
输入:
多组(不超过 5 组)数据。
每组输入数据分为三行，第一行有两个数字 n，m($0<n,m\leq10000$)，分别表示集合 A 和集合 B 的元素个 数。后两行分别表述集合 A 和集合 B。每个元素为不超出 int 范围的整数，每个元素之间有一个空格隔开。 输出: 针对每组数据输出一行数据，表示合并后的集合，要求从小到大输出，每个元素之间有一个空格隔开。 样例输入
12
1
23
12
1
12 
样例输出 
1 2 3
1 2
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m,n;
	while(cin>>m>>n)
	{
		set<int> s;
		for(int i = 0; i < m+n; ++i)
		{
			int x;
			cin>>x;
			s.insert(x);
		}
		for(set<int>::iterator it = s.begin(); it != s.end(); ++it)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
}
