#include<iostream>
using namespace std;

class Test
{
public:
	void test()
	{
		cout<<"Test::test()"<<endl;
	}
};

template<class _Ty>
class auto_ptr
{
public:
	//构造函数
	explicit auto_ptr(_Ty *_P = 0):_Owns(_P != 0),_Ptr(_P)
	{}	//必须要显式调用才行 关键字explicit
	//析构函数
	~auto_ptr()
	{
		if(_Owns)	//如果拥有权为真
			delete _Ptr;
	}
public:
	auto_ptr(const auto_ptr<_Ty> &_Y)//:_Owns(_Y._Owns),_Ptr(_Y.release())	//拷贝构造函数
	{
		_Owns = _Y._Owns;
		_Ptr = _Y.release();
	}
	auto_ptr<_Ty>& operator=(const auto_ptr<_Ty> &_Y)	//赋值构造函数
	{
		if(this != &_Y)	//如果不是自己给自己赋值
		{
			if(_Ptr != _Y._Ptr)	//指向的空间是否相同
			{
				if(_Owns)		//拥有权为真 释放自己所指向额空间
					delete _Ptr;
				_Owns = _Y._Owns;
			}
			else if(_Y._Owns)	//如果_Y的拥有权为真
			{
				_Owns = _Y._Owns;
			}
			//拥有权为假的情况 则不会将假的拥有权赋过来
			_Ptr  = _Y.release();
		}
		return *this;
	}
public:
	_Ty& operator*()const
	{
		return *get();
	}
	_Ty* operator->()const
	{
		return get();
	}
	_Ty* get()const
	{
		return _Ptr;
	}
	_Ty* release()	const	//const auto_ptr * const this
	{
		//_Owns = false;
		((auto_ptr<_Ty>*const)this)->_Owns = false;
		return _Ptr;
	}
private:
	//拥有权
	//mutable bool _Owns;		//为可变量
	bool _Owns;
	//指针
	_Ty	*_Ptr;
};

int main()
{
	/*
	int* p = new int(10);
	auto_ptr<int> pa(p);		//对象的释放会自动调用析构函数
	cout<<*pa<<endl;

	Test* pt = new Test;
	auto_ptr<Test> pb(pt);
	pb->test();
	*/
	/*
	cout<<"----------"<<endl;
	int *p = new int(10);
	auto_ptr<int> pa(p);
	//auto_ptr<int> pb(pa);//析构函数被调用了两次 内存泄漏
	auto_ptr<int> pb = pa;	//调用的也是拷贝构造函数
	*/

	int *p = new int(10);
	int *q = new int(20);
	auto_ptr<int>pa(p);
	auto_ptr<int>pb(q);

	pb = pa;
	cout<<"pb = "<<*pb<<endl;
	cout<<"pa = "<<*pa<<endl;
	//拥有权的转移并不是很彻底
	return 0;
}
