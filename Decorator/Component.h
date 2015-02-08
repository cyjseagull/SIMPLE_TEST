/*************************************************************************
    > File Name: Component.h
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sun 08 Feb 2015 04:00:10 PM CST
    > Function: 
    > Para:
 ************************************************************************/
#ifndef _COMPONENT_H_
#define _COMPONENT_H_
#include <iostream>
using namespace std;

class Component
{
	public:
		virtual void Operation()=0;
};


class ConcreteComponentA:public Component
{
	public:
		void Operation()
		{
			cout<<"operation of concreteComponetA"<<endl;
		}
};


class ConcreteComponentB:public Component
{
	public:
		void Operation()
		{
			cout <<"operation of concreteComponetB"<<endl;
		}
};

#endif
