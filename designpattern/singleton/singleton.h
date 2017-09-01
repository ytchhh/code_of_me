/*
	单例的一般实现比较简单，下面是代码和UML图。由于构造函数是私有的，因此无法通过构造函数实例化，唯一的方法就是通过调用静态函数GetInstance。
*/

class Singleton
{
public:
	static Singleton* GetInstance();
private:
	Singleton()
	{}
	static Singleton* singleton;
};

Singleton* Singleton::singleton = NULL;
Singleton* Singleton::GetInstance()
{
	if(Singleton == NULL)
		singleton new Singleton;
	return singleton;
}
