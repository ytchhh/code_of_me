/*
   小Q今天在上厕所时想到了这个问题：有n个数，两两组成二元组，差最小的有多少对呢？差最大呢？

   输入描述:

   输入包含多组测试数据。
   对于每组测试数据：
   N - 本组测试数据有n个数
   a1,a2...an - 需要计算的数据
   保证:
   1<=N<=100000,0<=ai<=INT_MAX.

   输出描述:

   对于每组数据，输出两个数，第一个数表示差最小的对数，第二个数表示差最大的对数。

   输入例子:

   6

   45 12 45 32 5 6

   输出例子:

   1 2
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int main()
{
		int n;
		while(cin>>n)
		{
				vector<int> a(n);
				for (int i=0;i<n;i++){
						cin>>a[i];
				}
				if(n==1){
						cout << 0<< " " <<0<< endl;
						continue;
				}
				sort(a.begin(),a.end());

				int maxnum=count(a.begin(),a.end(),a[n-1]);
				int minnum=count(a.begin(),a.end(),a[0]);
				int max=maxnum*minnum;
				int minvalue=a[1]-a[0];
				for(int i=1;i<n;i++){
						if(a[i]-a[i-1]<minvalue)
								minvalue=a[i]-a[i-1];
				}
				int min=0;
				for(int i=1;i<n;i++){
						for(int j=i-1;j>=0;j--){
								if(a[i]-a[j]==minvalue)
										min++;
								else
										break;
						}
				}
				if(a[0]==a[n-1]){
						int num=a.size()*(a.size()-1)/2;
						cout << num << " " <<num<< endl;
						continue;
				}
				cout << min << " " << max << endl;

		}
		return 0;
}
