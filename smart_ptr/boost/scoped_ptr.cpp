#include<iostream>
using namespace std;

template<class T>
void check_delete(T *x)
{
	typedef char type_must_be_complete[sizeof(T) ? 1 : -1];
	(void) sizeof(type_must_be_complete);
	delete x;
}

template<class T>
class scoped_ptr
{
public:
	explicit scoped_ptr(T *p = 0):px(p)
	{
	}
	~scoped_ptr()
	{
		check_delete(px);
	}
private:
	//将拷贝构造和赋值构造声明为私有 可以防止其拥有权的转移
	scoped_ptr(scoped_ptr<T> const &)
	{
	
	}
	scoped_ptr<T>& operator=(scoped_ptr<T> const &)
	{
		
	}
public:
	
	//重载函数
	T& operator*()const
	{
		return *px;
	}
	T* operator->()const
	{
		return px;
	}
	T* get()const
	{
		return px;
	}
	
	typedef scoped_ptr<T> this_type;

	void reset(T *p = 0)
	{
	//构建的一个临时对象 临时对象在其作用域之后会自动调用析构函数
		this_type(p).swap(*this);
	}
	void swap(scoped_ptr& b)
	{
		T *tmp = b.px;
		b.px = px;
		px = tmp;
	}
private:
	T *px;
};

int main()
{
	int *p = new int(10);
	int *q = new int(20);
	scoped_ptr<int> pa(p);
	cout<<"pa = "<<*pa<<endl;
	pa.reset(q);
	cout<<"pa = "<<*pa<<endl;
	scoped_ptr<int> pb;
	pb = pa;
	return 0;
}
