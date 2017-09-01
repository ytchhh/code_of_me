#include <iostream>
using namespace std;

union tagAAAA  
{
		struct
		{
				char  ucFirst;
				short usSecond;
				char  ucThird;
		}half;
		int  lI;
}number;

int main()
{
	cout<<sizeof(number)<<endl;
}
