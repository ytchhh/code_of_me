#include <iostream>
using namespace std;

/*
	参数的缺省值

	有一些参数的值在每次函数调用时都相同，书写这样的语句会使人厌烦。C++语言采用参数的缺省值使书写变得更加简洁(在编译时，缺省值由编译器自动插入)。
	参数缺省值得使用规则：
	1.参数缺省值只能出现在函数的声明中，而不能出现在定义体中。
	例如：
	void foo(int x = 0,int y = 0);		//正确，缺省值出现在函数的声明中
	void foo(int x = 0, int y = 0);		//错误，缺省值出现在函数的定义体中
	{
		....
	}
	在编译时会出现错误，因为函数的实现本来就与参数是否有缺省值无关，所以没有必要让缺省值出现在函数的定义体内。
	二是参数的缺省值可能会改动，显然修改函数的声明比修改函数的定义要方便。
void foo(int x = 0,int y = 0);

int main()
{
	
}

void foo(int x = 0, int y = 0)
{
	
}
*/

/*
	如果函数有多个参数，参数只能从后面挨个儿缺省，否则将会导致函数调用语句怪模怪样。
	正确的实例如下：
	void foo(int x,int y = 0,int z = 0);
	错误的示例如下：
	void foo(int x = 0,int y, int z = 0);
*/

void foo(int x,int y=0,int z=0);
void foo1(int x=0, int y, int z=0);

int main()
{
	
	return 0;
}

void foo(int x, int y, int z)
{
	
}

void foo1(int x, int y, int z)
{
	
}
/*
	要注意，使用参数的缺省值并没有赋予函数新的功能，仅仅是使书写变得更加简洁一些。它可能会提高函数的易用性，但是也可能降低函数的可理解性，所以我们只能适当地使用参数的缺省值，要防止使用不当产生负面效果。如下例：

void output(int x);
void output(int x,float y=0.0);

void output(int x)
{
	cout<<"output int "<<x<<endl;
}
void output(int x,float y)
{
	cout<<"output int "<<x<<"and float "<<y<<endl;
}

int main()
{
	int x = 1;
	float y = 0.5;
	output(x);		//error
	output(x,y);
}

*/
