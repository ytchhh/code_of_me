*
	子安字符串中找出第一个只出现一次的字符。如输入"abaccdeff"，则输出'b'。
*/

#include <iostream>
using namespace std;

char FirstNotRepaetingchar(char *pString)
{
	if(pString == NULL)
		return '\0';
	int tablesize = 256;
	unsigned int hashtable[tablesize];
	for(unsigned i = 0; i < tablesize; ++i)
		hashtable[i] = 0;
	
	char *key = pString;
	while(*key != '\0')
		hashtable[*key++]++;
	
	key = pString;
	while(*key != '\0')
	{
		if(hashtable[*key] == 1)
			return *key;
		++key;
	}
	return '\0';
}

int main()
{
	char *String = "aabbdceef";
	cout<<"first Number:"<<FirstNotRepaetingchar(String)<<endl;
}
