#pragma once


#include "./singletonA.h"


class SingletonA:public Singleton  
{  
	friend class Singleton; //必须为友元类，否则父类无法访问子类的构造函数  
public:  
	void Show() { cout<<"SingletonA"<<endl; }  
private:   //为保护属性，这样外界无法通过构造函数进行实例化  
	SingletonA() {}   
};  
