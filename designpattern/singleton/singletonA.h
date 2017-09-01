#pragma once

#include <string.h>

#include <iostream>
using namespace std;


class Singleton    
{  
public:  
	static Singleton* GetInstance(const char* name);  
	virtual void Show() {}  
protected: //必须为保护，如果是私有属性，子类无法访问父类的构造函数  
	Singleton() {}  
private:  
	static Singleton *singleton; //唯一实例的指针  
};  

 

