/*
	把数组排成最小的数
	输入一个正整数数组，把数组中所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3,32,321},则打印出这三个数字能排出的最小数字321323
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;


const int g_MaxNumberlength = 10;
char* g_StrCombine1 = new char[g_MaxNumberlength*2+1];
char* g_StrCombine2 = new char[g_MaxNumberlength*2+1];

int compare(const void* strnumbers1,const void* strnumbers2)
{
	strcpy(g_StrCombine1, *(const char**)strnumbers1);
	strcat(g_StrCombine1, *(const char**)strnumbers2);

	strcpy(g_StrCombine2, *(const char**)strnumbers2);
	strcat(g_StrCombine2, *(const char**)strnumbers1);

	return strcmp(g_StrCombine1, g_StrCombine2);
}

void printMinNumber(int *numbers, int length)
{
	if(numbers == NULL || length <= 0)
		return;
	char** strnumbers = (char**)(new int[length]);
	for(int i = 0; i < length; ++i)
	{
		strnumbers[i] = new char[g_MaxNumberlength];
		sprintf(strnumbers[i], "%d", numbers[i]);
	}
	qsort(strnumbers,length,sizeof(char*),compare);
	
	for(int i = 0; i < length; ++i)
		printf("%s", strnumbers[i]);
	printf("\n");

	for(int i = 0; i < length; ++i)
		delete[] strnumbers[i];
	delete[] strnumbers;
}

int main()
{
	int arr[] = {3,321,32};
	printMinNumber(arr, 3);
	return 0;
}
