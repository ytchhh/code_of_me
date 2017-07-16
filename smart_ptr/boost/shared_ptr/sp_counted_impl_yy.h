#pragma once

#include"./sp_counted_base.h"

template<class X>
class sp_counted_impl_yy:public sp_counted_base
{
private:
	X * px_;
public:
	sp_counted_impl_yy(X *px):px_(px)
	{
	#ifndef DISPLAY
		cout<<"Create sp_counted_impl_yy Object"<<endl;
	#endif
	}
	~sp_counted_impl_yy()
	{
	#ifndef DISPLAY
		cout<<"Free sp_counted_impl_yy Object"<<endl;
	#endif
	delete px_;
	}
	virtual void dispose()
	{
		//	delete px_;
		#ifndef DISPLAY
		cout<<"This is sp_counted_impl_yy:dispose()"<<endl;
		#endif
		delete this;
	}
}
;
