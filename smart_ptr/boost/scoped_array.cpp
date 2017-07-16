#include<iostream>
#include<boost/smart_ptr.hpp>

using namespace std;
using namespace boost;


int main()
{
	int *p = new int[10];
	scoped_array<int> pa(p);
	cout<<"*pa"<<*pa<<endl;
	return 0;
}
