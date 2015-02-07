/*************************************************************************
    > File Name: Singleton.h
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sat 07 Feb 2015 08:51:14 AM CST
    > Function: 
    > Para:
 ************************************************************************/

#ifndef _SINGLETON_H_
#define _SINGLETON_H_
#include <iostream>
using namespace std;

class Singleton
{
	public:
		static Singleton *Instance();
	protected:
		Singleton();
	private:
		static Singleton *_instance;
};

#endif
