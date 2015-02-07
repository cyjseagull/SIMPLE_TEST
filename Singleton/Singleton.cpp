/*************************************************************************
    > File Name: Singleton.cpp
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sat 07 Feb 2015 08:53:07 AM CST
    > Function: 
    > Para:
 ************************************************************************/

#include "Singleton.h"
#include "stdio.h"

Singleton *Singleton::_instance = NULL;

Singleton::Singleton()
{
	cout<<"Create Singleton..."<<endl;
}

Singleton* Singleton::Instance()
{
	if(_instance == NULL)
		_instance = new Singleton();

	return _instance;
}

