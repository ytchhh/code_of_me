#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n][2];
	for(int i = 0; i < n; ++i)
		cin>>a[i][0]>>a[i][1];
	int b[n] = {0};
	int temp1,temp2;
	int k = 0;
	for(int i = 0; i < n; ++i)
	{
		temp1 = a[i][0];
		temp2 = a[i][1];
		int j = 0;
		while( !(a[j][0]>temp1 && a[j][1]>temp2) && j < n )
		{
			j++;
		}
		if(j == n)
		{
			b[k++] = i;
		}
	}
	for(int i = 0; i < k; ++i)
		cout<<a[b[i]][0]<<" "<<a[b[i]][1]<<endl;
	return 0;
}
