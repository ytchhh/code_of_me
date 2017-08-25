/*
	格式化日期函数
*/

#include <assert.h>

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool IsLeapYear(int year)
{
	if((year%4==0 && year%100!=0) || year%400==0)
		return true;
	return false;
}

bool IsBigMonth(int month)
{
	if(month == 4 || month == 6 || month == 9 || month == 11)
		return false;
	return true;
}

wstring FormatDate(const wstring& format,int year,int month,int day)
{
	assert(year > 1000 && year <= 9999);
	assert(year >= 1 && month <= 12);
	assert(day >= 1);
	if(month == 2)
		IsLeapYear(year) ? assert(day <= 29) : assert(day <= 28);
	else if(IsBigMonth(month))
		assert(day <= 31);
	else
		assert(day <= 30);
	//上面所做的都是为了判断输入的数据是否合法
	wchar_t *resultstring = new wchar_t[12];
	vector<wstring> support_format;
	support_format.push_back(L"YYYYMMDD");
	support_format.push_back(L"YY/MM/DD");
	support_format.push_back(L"MM/DD/YYYY");

	if(format == support_format[0])
	{
		swprintf(resultstring,12,L"%.4d%.2d%.2d",year,month,day);
	}
	else if(format == support_format[1])
	{
		swprintf(resultstring,12,L"%.2d/%.2d/%.2d",year%100,month,day);
	}
	else if(format == support_format[2])
	{
		swprintf(resultstring,12,L"%.2d/%.2d/%.4d",month,day,year);
	}
	else
	{
		cerr<<"no this format"<<endl;
	}
	return wstring(resultstring);
}

int main()
{
	wstring format1(L"YYYYMMDD");
	wstring format2(L"YY/MM/DD");
	wstring format3(L"MM/DD/YYYY");
	wstring resultstring = FormatDate(format1,2017,8,23);
	wstring resultstring1 = FormatDate(format2,2017,8,23);
	wstring resultstring2 = FormatDate(format3,2017,8,23);
	wcout<<resultstring<<endl;
	wcout<<resultstring1<<endl;
	wcout<<resultstring2<<endl;
	return 0;
}
