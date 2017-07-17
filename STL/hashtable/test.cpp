#include <iostream>
#include <hashtable.h>
#include <bits/stl_function.h>
#include <hash_fun.h>
#include <ext/functional>

using namespace std;
using namespace __gnu_cxx;

int main()
{
	
	hashtable<int, int, __gnu_cxx::hash<int>, identity<int>, equal_to<int> > iht(50, __gnu_cxx::hash<int>(),equal_to<int>() );
	cout<<iht.size()<<endl;
	cout<<iht.bucket_count()<<endl;
	return 0;
}
