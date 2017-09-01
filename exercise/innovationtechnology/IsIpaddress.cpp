#include <string.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

bool IsIpaddr(char *ipaddr)
{
	if(ipaddr == NULL)
		return false;
	
	char *token;
	const char *delim = ".";
	token = strtok(ipaddr,delim);
	if(!token)
	{
		return false;
	}

	while(token)
	{
		int temp = atoi(token);
		if(temp < 0 || temp > 255)
		{
			return false;
		}
		token = strtok(NULL,delim); 
	}
	return true;
}

int main()
{
	const int length = 60;
	char ipaddr[length] = "192.168.0.28";

	if(IsIpaddr(ipaddr))
	{
		cout << "is ipaddr format" << endl;
	}
	else
	{
		cout << "is not ipaddr format" << endl;
	}

	return 0;
}
