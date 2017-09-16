#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	string temp;
	cin >> temp;
	
	long long val = std::stoll(temp);
	long long n = ( 1 + sqrt(1 + 8*val) )/2;
	cout << n << endl;
	return 0;
}
