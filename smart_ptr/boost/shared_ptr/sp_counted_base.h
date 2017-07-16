#pragma once

#include<iostream>
using namespace std;
#include"./config.h"


class sp_counted_base
{
public:
	sp_counted_base():use_count_(1)
	{
	#ifndef DISPLAY
		cout<<"Create sp_counted_base Object"<<endl;
	#endif
	}
	~sp_counted_base()
	{
	#ifndef DISPLAY
		cout<<"Free sp_counted_base Object"<<endl;
	#endif
	}
public:
virtual void dispose() = 0;
	void realease()//引用计数器减一 如果为0 调用摧毁函数
	{
		if(--use_count_ == 0)
		{
			this->dispose();
		}
	}
private:
	long use_count_;	//父类有一个引用计数器
};
