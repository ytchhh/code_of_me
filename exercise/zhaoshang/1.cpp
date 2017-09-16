nclude <iostream>
using namespace std;

int gcd(int first, int second)  
{  
		if(second == 0)  
				return first;  
		return  gcd(second,first%second);  
}  

int main()
{
		int a,b,c;
		cin >> a >> b >> c;
		int num;
		if(a > b)
				num = gcd(a, b);
		else
				num = gcd(b, a);

		num = a*b/num;
		int count = 0;
		for(; num <= c; ++num)
		{
				if(num%a==0 && num%b==0)
						++count;
		}
		cout << count << endl;
		return 0;
}
