/*************************************************************************
    > File Name: main.cpp
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Tue 10 Feb 2015 05:15:11 PM CST
    > Function: 
    > Para:
 ************************************************************************/

#include <iostream>
using namespace std;
#include "Strategy.h"

template<class T>
void DelPointer(T t)
{
	if(t)
	{
		delete t;
		t = NULL;
	}
}


int main()
{
	Strategy* s= new ConcreteStrategyA();
	Context* c = new Context(s);
	c->DoActionA();
	DelPointer(s);
	//DelPointer(c);
	
}
