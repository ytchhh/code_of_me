/*
	设计一个统计编号出现格式出现次数的函数，函数定义如下。
	void getNumberFormateCount(const string& format,vector<int>& vecCounts)
	执行步骤为先读取文件中的内容到vector中，然后再逐行解析，遇到所输入的格式，就进行++返回。然后再打印即可。
*/

#include <string.h>
#include <assert.h>

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


//读取文件
vector<string> readfile(string filename)
{
	vector<string> result;
	string charline;

	ifstream fin( filename.c_str() );
	assert( fin.is_open() );
	while( !fin.eof())
	{
		getline(fin,charline);
		cout<<charline<<endl;
		result.push_back(charline);
	}
	fin.close();
	return result;
}

int Count(const string& format,string& str)
{
	char temp_str[20];
	int j = 0,count = 0;
	for(int i = 0; i <= str.size(); ++i)
	{
		if(str[i] == ';' || str[i] == '\0')
		{
			temp_str[j] = '\0';
			string temp(temp_str);
			if(temp == format)
				return count;
			count++;
			j = 0;
			continue;
		}
		temp_str[j++] = str[i];
	}
	return -1;
}


void GetNumberFormateCount(const string& format,vector<int>& vecCounts)
{
	string filename("test.txt");
	vector<string> result = readfile(filename);
	for(int i = 0; i < 3; ++i)
		vecCounts.push_back(0);
	for(int i = 0; i < result.size(); ++i)
	{
		int j = Count(format,result[i]);
		if(j >= 0)
			vecCounts[j]++;
	}
}

int main()
{
	vector<int> vecCounts;
	string format("1.");
	GetNumberFormateCount(format,vecCounts);
	for(int i = 0; i < vecCounts.size(); ++i)
	{
		cout<<i+1<<" "<<vecCounts[i]<<endl;
	}
	return 0;
}

