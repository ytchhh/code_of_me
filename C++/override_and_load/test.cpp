/*
	成员函数的重载,覆盖与隐藏很容易混淆。C++程序员必须要弄清楚这些概念，否则错误将防不胜防

	重载与覆盖
		成员函数被重载的特征:
		(1)相同的范围(在同一个类中);
		(2)函数名字相同
		(3)参数不同
		(4)virtual关键字可有可无
		覆盖是指派生类函数覆盖基类函数，特征是:
		(1)不同的范围(分别位于派生类与基类)
		(2)函数名字相同
		(3)参数相同
		(4)基类函数必须有virtual关键字
*/


#include<iostream>
using namespace std;

#if 0

class Base
{
public:
	void f(int x)
	{
		cout<<"Base::f(int)"<<x<<endl;
	}
	void f(float x)
	{
		cout<<"Base::f(float)"<<x<<endl;
	}
	virtual void g(void)
	{
		cout<<"Base::g(void)"<<endl;
	}
};

class Derived:public Base
{
public:
	virtual void g(void)
	{
		cout<<"Derived::g(void)"<<endl;
	}
};

int main()
{
	Derived d;
	Base *pb = &d;
	pb->f(42);		//Base::f(int) 42
	pb->f(3.14f);	//Base::f(float) 3.14
	pb->g();		//Derived::g(void)
	return 0;
}

#endif


#if 0

class man
{
public:
	void look()
	{
		cout<<"man"<<endl;
	}
};

class superman:public man
{
public:
	void fly()
	{
		cout<<"fly"<<endl;
	}
	void look()
	{
		cout<<"superman"<<endl;
	}
};

int main()
{
	man *p = new man;
	man *p1 = new superman;
	//superman *p3 = new man;		//error
	((superman*)p)->fly();
	((superman*)p1)->fly();

	p1->look();
	return 0;
}


#endif

#if 1

/*
	隐藏
	(1)如果派生类的函数与基类的函数同名，但是参数不同。此时不论有无virtual关键字，基类的函数将被隐藏(注意别与重载混淆)
	(2)如果派生类的函数与基类的函数同名，并且参数也相同，但是基类函数没有virtual关键字。此时，基类的函数被隐藏(注意别与覆盖混淆)
*/

class Base
{
public:
	virtual void f(float x)
	{
		cout<<"Base::f(float)"<<endl;
	}
	void g(float x)
	{
		cout<<"Base::g(float)"<<endl;
	}
	void h(float x)
	{
		cout<<"Base::h(float)"<<endl;
	}
};
class Derived:public Base
{
public:
	void f(float x)
	{
		cout<<"Derived::f(float)"<<endl;
	}
	void g(int x)
	{
		cout<<"Derived::g(int)"<<endl;
	}
	void h(float x)
	{
		cout<<"Derived::h(float)"<<endl;
	}
};

int main()
{
	Derived d;
	Base *pb = &d;
	Derived *pd = &d;
	pb->f(3.14f);
	pd->f(3.14f);

	pb->g(3.14f);
	pd->g(3.14f);

	pb->h(3.14f);
	pd->h(3.14f);
	return 0;
}
#endif

