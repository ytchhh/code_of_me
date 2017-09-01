/*
	【题目 述】游戏里面有很多各种各样的任务，其中有一种任务玩家只能做一次，这类任务一共有 1024 个， 任务 ID 范围[1,1024].请用 32 个 unsigned int 类型来记录着 1024 个任务是否已经完成。初始状态为未完 成。
	输入两个参数，都是任务 ID，需要设置第一个 ID 的任务为已经完成;并检查第二个 ID 的任务是否已经完 成。
	输出一个参数，如果第二个 ID 的任务已经完成输出 1，如果未完成输出 0,。如果第一或第二个 ID 不在 [1,1024]范围，则输出 1.
	如:
	输入:
	1024 1024
	输出:
	1
	测试用例:
	1、
	输入:1024 1024 输出:1
	2、
	输入:1024 1023 输出:0
	3、
	输入:1022 1025 输出:-1
*/

/*
	因为一个unsigned int的刚好是32位，32个unsigned int类型刚好是1024位。所以用位运算即可。
*/

#include <bits/stdc++.h>
using namespace std;


int main()
{
	int a,b;
	cout<<sizeof(a)<<endl;
	cin>>a>>b;
	if(a < 1 || a > 1024 || b < 1 || b > 1024)
	{
		cout<<-1<<endl;
		return 0;
	}
	int index,temp;
	unsigned int count[32] = {0};
	index = (a-1)/32;
	temp = (a-1)%32;
	count[index] |= 1<<temp;

	index = (b-1)/32;
	temp = (b-1)%32;

	if(count[index] & 1<<temp)
		cout<<1<<endl;
	else
		cout<<-1<<endl;
	return 0;
}
