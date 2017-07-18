#include <iostream>

using namespace std;
using namespace __gnu_cxx;

#include <hashtable.h>
#include <bits/stl_function.h>
#include <hash_fun.h>
#include <ext/functional>
int main()
{
	
	hashtable<int, int, __gnu_cxx::hash<int>, identity<int>, equal_to<int> > iht(50, __gnu_cxx::hash<int>(),equal_to<int>() );
	cout<<"size = "<<iht.size()<<endl;
	cout<<"bucket size = "<<iht.bucket_count()<<endl;
	cout<<"max bucket size = "<<iht.max_bucket_count()<<endl;

	iht.insert_unique(1);
	iht.insert_unique(54);
	iht.insert_unique(0);
	iht.insert_unique(7);

	cout<<"size = "<<iht.size()<<endl;
	cout<<"bucket size = "<<iht.bucket_count()<<endl;
	cout<<"max bucket size = "<<iht.max_bucket_count()<<endl;

	return 0;

