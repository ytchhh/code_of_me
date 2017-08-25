#include <stdlib.h>

#include <iostream>
using namespace std;

int compar(const void *a,const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	long long int n;
	cin>>n;
	int a[n];
	for(long long int i = 0; i < n; ++i)
		cin>>a[i];
	qsort(a,n,4,compar);
	int b[2];
	b[0] = a[n-1]*a[n-1];
	b[1] = 1;
	for(long long int i = 0; i < n; ++i)
		b[1]*= a[i];
	if(b[0] > b[1])
		cout<<b[0]<<endl;
	else
		cout<<b[1]<<endl;


	return 0;
}
