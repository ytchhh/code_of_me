#include<iostream>
#include"./smart_ptr.h"
using namespace std;

int main()
{
	int *p = new int(10);
	shared_ptr<int> pa(p);
	return 0;
}
