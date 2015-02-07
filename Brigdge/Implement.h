/*************************************************************************
    > File Name: implement.h
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sat 07 Feb 2015 08:27:20 PM CST
    > Function: 
    > Para:
 ************************************************************************/
#ifndef _IMPLEMENTOR_H_
#define _IMPLEMENTOR_H_
#include <iostream>
using namespace std;


//interface
class Implementor
{
	public:
		virtual void Operation(){}
	
};


class ConcreteImplementorA:public Implementor
{
	public:
		virtual void Operation();

};

class ConcreteImplementorB:public Implementor
{
	public:
		virtual void Operation();
};

#endif


