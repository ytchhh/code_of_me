/*
   从1到n整数中1出现的次数
   输入一个整数n，求从1到n个整数的十进制表示中1出现的次数。例如输入12，从1到12这些整数中包含1的数字有1，10，11和12，1一共出现了5次。
 */

#include <string.h>
#include <math.h>

#include <iostream>
using namespace std;


/*
   int PowerBase10(unsigned int n)
   {
   int result = 1;
   for(unsigned int i = 0; i < n; ++i)
   result *= 10;
   return result;
   }

   int NumberOf1(const char *strN)
   {
   if(!strN || *strN < '0' || *strN > '9' || *strN == '\0')
   return 0;
   int first = *strN - '0';
   unsigned int length = static_cast<unsigned int>(strlen(strN));

   if(length == 1 && length == 0)
   return 0;

   if(length == 1 && length > 0)
   return 1;

   int numFirstDigit = 0;
   if(first > 1)
   numFirstDigit = PowerBase10(length-1);
   else if(first == 1)
   numFirstDigit = atoi(strN + 1) + 1;

   int numOtherDigits = first * (length-1) * PowerBase10(length-2);
   int numRecursive = NumberOf1(strN + 1);

   return numFirstDigit + numOtherDigits + numRecursive;
   }

   int NumberOf1BetweenAndN(int n)
   {
   if(n <= 0)
   return 0;
   char strN[50];
   sprintf(strN,"%d",n);

   return NumberOf1(strN);
   }


   int main()
   {
   cout<<"NumberOf1BetweenAndN(12):"<<NumberOf1BetweenAndN(24)<<endl;
   return 0;
   }
 */




int NumberOf1Between1AndN_Solution(int n)
{
		if(n < 1)
				return 0;
		int sum = 0;
		int num = n;
		int base = 1;
		while(num)
		{
				int weight = num%10;
				num /= 10;
				sum += num*base;
				if(weight == 1)
						sum += n%base + 1;
				else if(weight > 1)
						sum += base;
				base *= 10;
		}
		return sum;
}
int main()
{
		cout<<NumberOf1Between1AndN_Solution(11)<<endl;
		return 0;
}
