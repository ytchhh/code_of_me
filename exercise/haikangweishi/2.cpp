#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
		string src,del;
		cin >> src >> del;

		char * p=(char*)src.data();
		char* temp = strtok(p,del.c_str());
		while(temp)
		{
				printf("%s\n",temp);
				temp = strtok(NULL,del.c_str());
		}


		return 0;
}
