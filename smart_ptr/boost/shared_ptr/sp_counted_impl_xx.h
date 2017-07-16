#pragma once

#include"./sp_counted_base.h"

template<class X>
class sp_counted_impl_xx:public sp_counted_base
{
private:
	X * px_;	//子类有相应的指针
public:
	sp_counted_impl_xx(X *px):px_(px)
	{
	#ifndef DISPLAY
		cout<<"Create sp_counted_impl_xx Object"<<endl;
	#endif
	}
	~sp_counted_impl_xx()
	{
	#ifndef DISPLAY
		cout<<"Free sp_counted_impl_xx Object"<<endl;
	#endif
	delete px_;
	}
	virtual void dispose()
	{
		//	delete px_;
		#ifndef DISPLAY
		cout<<"THis is sp_counted_impl_xx:dispose()"<<endl;
		#endif
		delete this;
	}
}
;
