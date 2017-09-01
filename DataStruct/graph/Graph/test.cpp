#include <stdio.h>
//#include <iostream>
//using namespace std;


int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	
	int sum1 = 0;
	int a1 = n/a;
	int a2 = m/b;
	if(a1 > a2)
	{
		a1 = a1-a2;
		sum1 += a2*x;
		sum1 += a1*a/d*z;
		sum1 += m%b/c*y;
	}
	else if(a1 < a2)
	{
		a2 = a2-a1;
		sum1 += a1*x;
		sum1 += a2*b/c*y;
		sum1 += n%a/d*z;
	}
	int sum2 = n/d*z + m/c*y;
	if(n%d && m%c)
	{
		int k = n%d*d/a > m%c*c/b ? m%c*c/b : n%d*d/a;
		sum2 += k*x;
	}
	int sum = (sum1 > sum2) ? sum1 :sum2;
	printf("%d\n",sum);
	return 0;
}


/*
#include <stdio.h>

#include <iostream>
using namespace std;



int main()
{
	long long int n;
	scanf("%lld",&n);
	long long int a[n],b[n];
	for(long long int i = 0; i < n; ++i)
	{
		scanf("%lld",&a[i]);
	}
	for(long long int i = 0; i < n; ++i)
	{
		long long count = 0;
		for(long long int j = 0; j < i; ++j)
		{
			if(a[j] > a[i])
				count++;
		}
		b[i] = count;
	}
	for(long long int i = 0; i < n; ++i)
	{
		printf("%lld ",b[i]);
	}
	printf("\n");
}
*/
