/*
-------------------------------------------------
C++11新特性

create by yangtingcheng
--------------------------------------------------
*/

#include <iostream>
#include <typeinfo>
#include <vector>
#include <map>
#include <assert.h>
#include <algorithm>
using namespace std;
#if 0

/*
新的关键字 auto
auto自动类型推导,用于从初始化表达式中推断出变量的数据类型，通过auto的自动类型推导，可以大大简化我们的编程工作。
auto实际上在编译时对变量进行了类型推导，多以不会对程序的运行效率造成不良影响。
另外。似乎auto并不会影响编译速度，因为编译时本来也要在右侧推导然后判断与左侧是否匹配
*/

int main()
{
//  auto a;				//错误的定义方式,必须要初始化表达式
	auto i =1;
	cout<<typeid(i).name()<<endl;
	auto d = 1.0;
	cout<<typeid(d).name()<<endl;
	auto str = "Hello World";
	cout<<typeid(str).name()<<endl;
	auto ch = 'A';
	cout<<typeid(ch).name()<<endl;
	auto func = less<int>();
	cout<<typeid(func).name()<<endl;
	vector<int> iv;
	auto ite = iv.begin();
	cout<<typeid(ite).name()<<endl;
	return 0;
}

/*
	auto在模板中大显身手，抛弃了模板参数的很多麻烦，真个代码都变得更加简洁。
*/

#endif

#if 0
//decltype实际上有点像auto的反函数，auto可以用让你声明一个变量，而decltype则可以从一个变量或表达式中得到类型。

int main()
{
	auto x = 3;
	decltype(x) y = x;
	return 0;
}
#endif

#if 0
/*
	nullptr是为了解决原来C++中NULL的二义性问题而引起的一种新的类型，因为NULL实际上代表的是0.
*/

void F(int a)
{
	cout<<a<<endl;
}
void F(int *p)
{
	assert(p != NULL);
	cout<<p<<endl;
}

int main()
{
	int *p = nullptr;
	int *q = NULL;
	bool equal = (p == q);	//equal的值为true，说明p和q都是空指针
	int a = nullptr;	//编译失败，nullptr不能转型为int
	int b = NULL;
	F(0);				//在C++98编译失败，有二义性，在C++11中调用F(int)
	F(nullptr);
	return 0;
}
#endif


#if 0

/*
	序列for循环，在c++中for循环可以使用类似java的简化的for循环，可以用于遍历数组，容器，string以及begin和end函数定义的序列，
*/

int main()
{	
	map<int,string>	m{{6,"a"},{3,"b"},{2,"c"}};
	for(auto p : m)
	{
		cout<<p.first<<":"<<p.second<<endl;
	}
	return 0;
}
#endif

#if 0
/*
	在引入C++11之前，只有数组能使用初始化列表，其他容器想要使用初始化列表，只能用以下方法
*/

int main()
{
	//int arr[3] = {1,2,3};
	//vector<int> v(arr,arr+3);
	int arr1[3]{1,2,3};
	vector<int> iv{1,2,3};
	map<int,string> m{{1,"a"},{2,"b"}};
	string str{"Hello World"};
	cout<<str<<endl;
	for(auto p : m)
		cout<<p.first<<":"<<p.second<<endl;
	return 0;
}

#endif


#if 0
/*
	lambda表达式
	其类似于javascript中的闭包，它可以用来创建并定义匿名的函数对象，以简化编程工作，Lambda的语法如下：
	[函数对象参数] (操作符重载函数参数) -> 返回值类型{函数体}

*/
int main()
{
	vector<int> iv{5,4,3,2,1};
	int a = 2,b = 1;

	for_each(iv.begin(),iv.end(),[b](int&x){cout<<(x+b)<<endl;});		//  (1)
	cout<<"------------"<<endl;
	for_each(iv.begin(),iv.end(),[=](int&x){cout<<x<<endl;x *= (a+b);});				//  (2)
	cout<<"------------"<<endl;
	for_each(iv.begin(),iv.end(),[=](int&x)->int{cout<<x<<endl;return x*(a+b);});		//  (3)
	return 0;
}

/*
	[]内参数指的是Lambda表达式可以取得的全局变量，(1)函数中的b就是指函数可以得到在Lambda表达式外的全局变量，
如果在[]中传入=的话，即是可以取得所有的外部变量，如(2)和(3)Lambda表达式
	()内的参数是每次调用函数时传入的参数
	->后加上的是Lambda表达式返回值的类型，如(3)中返回了一个int类型的变量.
*/
#endif

#if 1

/*
	我们在C++中搜用过pair，，用pair可以使用make_pair构造，构造一个包含两种不同类型的数据的类型，比如：以下代码：
	auto p = make_pair(1,"C++11");
	由于在C++11中引入了变长参数模板，所以发明了新的数据类型，tuple，tuple是一个N元组，可以传入一个，2个甚至多个不同类型的数据。
	auto t1 = make_tuple(1,2.0,"C++11");
	auto t2 = make_tuple(1,2.0,"C++11",{1,0,2});
	这样就避免了以前的pair中嵌套pair的丑陋做法，使得代码更加简洁。
	另一个经常见到的例子就是Print函数，在C语言中printf可以传入多个参数，在C++11中，我们可以用变长参数模板实现更简洁的Print.
	template<class Head,class... Tail>
	void Print(Head head,class... Tail)
	{
		cout<<head<<endl;
		Print(Tail);
	}
	Print中可以传入多个不同类型的参数，如下：
	Print(1,1.,"C++11");
*/
int main()
{
	
	return 0;
}
#endif

