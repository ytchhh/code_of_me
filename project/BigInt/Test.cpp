#include<iostream>
#include<unistd.h>
#include"bigint.h"
using namespace std;

int main()
{
	BigInt bt,bt1,bt2;
	bt.LoadData(3);
	cout<<"bt1 = ";
	bt1.PrintData();
	sleep(1);
	bt2.LoadData(4);
	cout<<"bt2 = ";
	bt2.PrintData();

	BigInt::Add(bt,bt1,bt2);
	cout<<"bt = ";
	bt.PrintData();
	return 0;
}
