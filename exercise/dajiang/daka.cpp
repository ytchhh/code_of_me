#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;
int main()
{
		int N;
		cin>>N;
		vector<string> vec;
		map<string, vector<int> > hashtable;  //输出要按照时间大小，所以用map，拥有自动排序功能。
		if (getchar()  == '\n') 
		{
			;
		}
		for (int i = 0; i < N; i++) 
		{
			string s;
			getline(cin, s);
			vec.push_back(s);
		}
		int mapMonthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //这个映射用来表示每个月有多少天
		for (int i = 0; i < vec.size(); i++)
		{
			string temp = vec[i];
			for (int j = 0; j < temp.size(); j++) 
			{
				if (temp[j] == ' ') 
				{
					string key = temp.substr(0, j);
					string value = temp.substr(j + 1);
					string time = value;
					int hour = atoi((time.substr(0, time.find(':'))).c_str());
					time = time.substr(time.find(':') + 1);
					int min = atoi((time.substr(0, time.find(':'))).c_str());
					int second = atoi(time.substr(time.find(':') + 1).c_str());
					int seconds = hour * 60 * 60 + min * 60 + second;
					if (hour >= 3) 
					{  //如果时间大于等于凌晨3点
						hashtable[key].push_back(seconds - 3 * 60 * 60); //以凌晨3点为基准，重新计算，单位秒，作为时间轴。
					} else 
					{  //时间小于凌晨3点
						int months = atoi(key.substr(0, key.find('.')).c_str());
						int days = atoi(key.substr(key.find('.') + 1).c_str());
						if (days != 1) 
						{       //如果日期不是1号，要往前算一天
							string month = to_string(months);
							if (months < 10) 
							{  //考虑数字是否小于10，小于10，需要在字符串中加"0"
								month = string("0") + month;
							} 
							string day = to_string(days - 1);
							if (days - 1 < 10) 
							{
								day = string("0") + day;
							}
							key = month + string(".") + day;
						} 
						else
						{ //如果是一号，月份同样往前算一个月（这里没有从1月份往前推，估计应该不太可能）
							string month = to_string(months - 1);
							if (months - 1 < 10) 
							{
								month = string("0") + month;
							}
							string day = to_string(mapMonthDays[months - 2]);
							if (mapMonthDays[months - 2] < 10) 
							{
								day = string("0") + day;
							}
							key = month  + string(".") + day;
						}
						hashtable[key].push_back(seconds + 21 * 60 * 60);  //所有时间以凌晨3点为基准，重新计算
					}
					break;
				}
			}
		}
		map<string, vector<int> >::iterator iter = hashtable.begin();
		int idle_start = 12 * 60 * 60 + 30 * 60 - 3 * 60 * 60; //休息起始时间
		int idle_end = 14 * 60 * 60 - 3 * 60 * 60; //休息结束时间
		for (; iter != hashtable.end(); iter++) 
		{
				if ((iter->second).size() >= 2) 
				{
					sort((iter->second).begin(), (iter->second).end()); //对时间进行排序
					vector<int> temp = iter->second;
					int result = 0;
					if (temp[temp.size() - 1] < idle_start) 
					{  //考虑工作时间段与休息时间段的重叠，每次先固定最后打卡时间点，再分析最先打卡时间点
						result = temp[temp.size() - 1] - temp[0];
					} 
					else if (temp[temp.size() - 1] >= idle_start && temp[temp.size() - 1] < idle_end) 
					{
						if (temp[0] < idle_start) 
						{ 
							result = idle_start - temp[0];
						}
					} 
					else 
					{
						if (temp[0] < idle_start) 
						{
							result = idle_start - temp[0] - (1 * 60 * 60  + 30 * 60);
						}
						else if(temp[0] >= idle_start && temp[0] < idle_end) 
						{
							result = temp[temp.size() - 1] - idle_end;
						}
						else 
						{
							result = temp[temp.size() - 1] - temp[0];
						}
					}
					if (result > 0) 
					{
						cout<<iter->first<<" "<<temp[temp.size() - 1] - temp[0]<<endl;
					}
				}
		}
		return 0;
}

