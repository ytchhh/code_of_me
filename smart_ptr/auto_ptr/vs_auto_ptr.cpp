#include<iostream>
using namespace std;

template<class _Ty>
class auto_ptr
{
	typedef auto_ptr<_Ty> _Myt;
public:
	explicit auto_ptr(_Ty *_Ptr = 0):_Myptr(_Ptr)
	{}
	~auto_ptr()
	{
		delete _Myptr;
	}
public:
	auto_ptr(_Myt& _Right):_Myptr(_Right.release())
	{
		
	}
	_Myt& operator=(_Myt& _Right)
	{
		reset(_Right.release());
		return *this;
	}
	_Ty& operator*() const
	{
		return	(*get());
	}
	_Ty* operator->()const
	{
		return get();
	}
	_Ty* get() const
	{
		return (_Myptr);
	}
	_Ty* release()	//释放函数
	{
		_Ty	*_Tmp = _Myptr;		//将当前指针给一个临时变量
		_Myptr = 0;				//指向NULL
		return _Tmp;		//返回
	}
	//重设函数
	void reset(_Ty *_Ptr = 0)
	{
		if(_Ptr != _Myptr)	//如果设置的指针和本身不一样
			delete _Myptr;
		_Myptr = _Ptr;
	}
private:
	//成员为一个指针
	_Ty *_Myptr;
};

int main()
{
	/*
	int *p = new int(10);
	auto_ptr<int> pa(p);
	cout<<"pa = "<<*pa<<endl;
	*/
	int *p = new int(10);
	int *q = new int(20);
	auto_ptr<int> pa(p);
	cout<<"pa = "<<*pa<<endl;
	pa.reset(q);
	cout<<"pa = "<<*pa<<endl;
	auto_ptr<int> pb = pa;
	cout<<"pa = "<<*pa<<endl;	//拥有权已经转移，无法输出，内存错误。
	return 0;
}
