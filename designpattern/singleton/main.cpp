
#include "./singletonA.h"

int main()
{
	Singleton *st = Singleton::GetInstance("SingletonA");
	Singleton *st1 = Singleton::GetInstance("SingletonB");
	st1->Show();
	st->Show();
	return 0;
}

/*
	上面代码有一个地方很诡异，父类为子类的友元，如果不是友元，函数GetInstance会报错，意思就是无法调用SingletonA和SIngletonB的构造函数。父类中调用子类的构造函数，我还是第一次碰到。当然了把SingletonA和SIngletonB的属性设为public，GetInstance函数就不会报错了，但是这样外界就可以定义这些类的对象，违反了单例模式。
	       看似奇怪，其实也容易解释。在父类中构建子类的对象，相当于是外界调用子类的构造函数，因此当子类构造函数的属性为私有或保护时，父类无法访问。为共有时，外界就可以访问子类的构造函数了，此时父类当然也能访问了。只不过为了保证单例模式，所以子类的构造函数不能为共有，但是又希望在父类中构造子类的对象，即需要调用子类的构造函数，这里没有办法才出此下策：将父类声明为子类的友元类。
*/
