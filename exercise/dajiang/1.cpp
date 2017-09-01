#include <stdio.h>

static unsigned int count = 0;

void print(unsigned int n,unsigned int m)
{
	unsigned int k = n^m;
	while(k)
	{
		k = k&(k-1);
		count++;
	}
}

int main()
{
	unsigned int n;
	scanf("%ud",&n);
	unsigned int a[n];
	for(unsigned int i = 0; i < n; ++i)
	{
		scanf("%ud",&a[i]);
	}
	for(unsigned int i = 0; i < n; ++i)
	{
		for(unsigned int j = i+1; j < n; ++j)
		{
			print(a[i],a[j]);
		}
	}
	printf("%u\n",count);
	return 0;
}
