/*
	C++语言采用重载机制的另一个理由是:类的构造函数需要重载机制。因为C++规定 
、构造函数与类同名(请参 第 9 章)，构造函数只能有 个名字。如果想用几种不同的方法
创建对象该怎么办?别 选择，只能重载机制来实现。所以类可以有多个同名的构造函数。
	
	几个同名重载的函数仍然是不同的函数，它们是如何区分的呢？我们自然想到函数接口的两个要素：参数和返回值。
	如果同名函数的参数不同（包括类型、顺序不同，那么容易区别出它们是不同的函数）。
	如果同名函数仅仅是返回值类型不同，有时可以区分，有时却不能。例如：
	void Function(void);
	int Function(void);
	上述两个函数，第一个没有返回值，第二个的返回值是int类型。如果这样调用函数：
	int x = Function();
	则可以判断出Function是第二个函数。问题是在C++/C程序中，我们可以忽略函数的返回值。在这种情况下，编译器和程序员都不知道哪个Function函数被调用。
	所以只能靠参数而不能靠返回值类型的不同来区分重载函数。编译器根据参数为每个重载函数产生不同的内部标识符。比如：
	void eat(beef);
	void eat(fish);
	void eat(chicken);
	_eat_fish	_eat_beef	_eat_chicken
	如果C++程序要调用已经被编译后的C函数，该怎么办？
	假设某个C函数的声明如下：
	void foo(int x,int y);
	该函数被C函数编译后在库中的名字为_foo，而C++编译器则会产生像_foo_int_int之类的名字用来支持函数重载和类型安全连接。由于编译后的名字不同，C++程序不能直接调用C函数。C++提供了一个C连接交换指定符号extern "C"来解决问题。
	例如：
		extern "C"
		{
			void foo(int x,int y);
		}
		或者写成
		extern "C"
		{
			#include "myheader.h"
		}
		这就告诉C++编译器，函数foo是个C连接，应该到库中找名字_foo而不是找_foo_int_int。C++编译器开发商已经对C标准库的头文件作了extern "C"处理，所以我们可以用#include直接引用这些头文件。
		注意并不是两个函数的名字相同就能构成重载。全局函数和类的成员函数同名不算重载，因为函数的作用域不同。例如：
		void Print();		//全局函数
		class A
		{
			void Print();	//成员函数
		};
		不论两个Print函数的参数是否相同，如果类的某个成员函数要调用全局函数Print，为了与成员函数Print区别，全局函数被调用时应加'::'标志。如：
		::Print();	//表示Print是全局函数而非成员函数。

*/

//当心隐式类型转换导致重载函数产生二义性

#if 1

#include <iostream>
using namespace std;

void output(int x);		//函数声明
void output(float x);	//函数声明

void output(int x)
{
	cout << "output int" << x <<endl;
}

void output(float x)
{
	cout << "output float" << x <<endl;
}

int main()
{	
	int x = 1;
	float y = 1.0;
	output(x);		//output int 1
	output(y);		//output float 1
	
	output(1);		//output int 1
//	output(0.5);		//error 具有二义性，

	output(int(0.5));	//output int 0
	output(float(0.5));	//output float 0.5
	return 0;
}

/*
	第一个output函数的参数是int类型，第二个output函数的参数是float类型。由于数字本身没有类型，将数字当做参数时将自动进行类型转换（称为隐式类型转换）。语句output(0.5)将产生编译错误，因为编译器不知道将0.5转换成int还是float类型的参数。隐式转换类型在很多地方可以简化为程序的书写，但是也可能留下隐患。
*/
#endif


