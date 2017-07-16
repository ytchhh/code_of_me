#ifndef _SHARED_COUNT_H
#define _SHARED_COUNT_H

#include"./sp_counted_base.h"
#include"./sp_counted_impl_xx.h"
#include"./sp_counted_impl_yy.h"

class shared_count
{
private:
	sp_counted_base *pi_;	//一个父类对象 可以直接，可以用子类实现
public:
	shared_count():pi_(0)
	{
		cout<<"Create shared_count Object"<<endl;
	}
//	template<class Y>
//	shared_count(Y *p):pi_(new sp_counted_impl_xx<Y>(p))
	template<class Y>
	shared_count(Y *p)
	{
	#ifndef DISPLAY
		cout<<"Create shared_count Object"<<endl;
	#endif
	//动态 定义了哪个子类 就用哪个子类去实现
	#ifndef SP_COUNTED_IMPL_XX
		pi_ = new sp_counted_impl_xx<Y>(p);
	#else
		pi_ = new sp_counted_impl_yy<Y>(p);
	#endif
	}
	virtual ~shared_count()
	{
	#ifndef DISPLAY
		cout<<"Free shared_count Object"<<endl;
	#endif
		if(pi_ != 0)	//如果所指向的不为空的话
						//调用相应的释放函数
			pi_->realease();
	}

};

#endif
