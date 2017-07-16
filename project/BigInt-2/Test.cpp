#include<iostream>
#include<unistd.h>
#include"bigint.h"
using namespace std;

/*
int main()
{
	BigInt bt(-100);
	cout<<"bt = "<<bt<<endl;
	return 0;
}
*/

/*
int quick(int a,int b,int c)  
{
    int ans=1; 
    a=a%c;  
    while(b!=0)  
    {  
        if(b & 1) //101010101011  -->
		{
			ans=(ans*a)%c;  
		}
        a = ( a * a ) % c;
		b >>= 1;  //
    }  
    return ans;  
}
void main()
{
	cout<<quick(2749194,3491491,5)<<endl;
}

/*
void main()
{
	BigInt bt,a(2749191),b(314143),n(5);
	BigInt::PowMod(bt, a, b, n);
	cout<<"bt = "<<bt<<endl;
}

/*
void main()
{
	BigInt bt,bt1,bt2;
	bt1.LoadData(10);
	Sleep(1000);
	bt2.LoadData(3);
	cout<<"bt1 = "<<bt1<<endl;
	cout<<"bt2 = "<<bt2<<endl;
	BigInt::Mod(bt, bt1, bt2);
	//cout<<"bt1 = "<<bt1<<endl;
	cout<<"bt  = "<<bt<<endl;
}


/*
void main()
{
	BigInt bt, bt1,bt2;
	bt1.LoadData(1000);
	Sleep(1000);
	bt2.LoadData(1000000);
	cout<<"bt1="<<bt1<<endl;
	cout<<"bt2="<<bt2<<endl;

	BigInt::Mul(bt, bt1, bt2); 
	cout<<"bt="<<bt<<endl;
}

/*
void main()
{
	BigInt a, b;
	a.LoadData(8);
	Sleep(1000);
	b.LoadData(10);

	cout<<"a = "<<a<<endl;
	cout<<"b = "<<b<<endl;
	a += b;
	cout<<"a = "<<a<<endl;
}

/*
#define RAND

#ifndef RAND
void main()
{
	BigInt bt, bt1(1000), bt2(100);
	cout<<"bt1=";
	bt1.PrintData();
	cout<<"bt2=";
	bt2.PrintData();

	BigInt::Sub(bt, bt1, bt2); 
	cout<<"bt=";
	bt.PrintData();
}

*/
int main()
{
	BigInt bt, bt1, bt2;
	bt1.LoadData(3);
	cout<<"bt1=";
	bt1.PrintData();
	sleep(1);
	bt2.LoadData(3);
	cout<<"bt2=";
	bt2.PrintData();

	BigInt::Sub(bt, bt1, bt2); //bt = bt1 - bt2;
	cout<<"bt=";
	bt.PrintData();
	return 0;
}
