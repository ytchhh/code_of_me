#ifndef _SHARED_PTR_H
#define _SHARED_PTR_H

#include"./shared_count.h"

template<class T>
class shared_ptr
{
public:
	shared_ptr(T *p = 0):px(p),pn(p)
	{
		#ifndef DISPLAY
		cout<<"Create shared_ptr"<<endl;
		#endif
	}
	~shared_ptr()
	{
	#ifndef DISPLAY
		cout<<"Free shared_ptr Object"<<endl;
	#endif
	}
private:
	T *px;			//指针
	shared_count pn;	//共享类型计数器
};

#endif
