#include "./singletonA.h"
#include "./singleton1.h"
#include "./singleton2.h"


Singleton* Singleton::singleton = NULL;  
Singleton* Singleton::GetInstance(const char* name)  
{  
	if(singleton == NULL)  
	{  
		if(strcmp(name, "SingletonA") == 0)  
				singleton = new SingletonA();  
		else if(strcmp(name,"SingletonB") == 0)  
				singleton = new SingletonB();  
		else   
				singleton = new Singleton();  
	}  
	return singleton;  
} 
