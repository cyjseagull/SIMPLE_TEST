/*************************************************************************
    > File Name: main.cpp
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sat 07 Feb 2015 08:51:33 PM CST
    > Function: 
    > Para:
 ************************************************************************/
#include "Implement.h"
#include "Abstraction.h"

int main()
{
	Implementor *op_impl = new ConcreteImplementorB();
	Abstraction *bridge = new RefinedAbstraction(op_impl);
	bridge->Operation();

	if(op_impl)
	{
		delete op_impl;
		op_impl = NULL;
	}
	if(bridge)
	{
		delete bridge;
		bridge = NULL;
	}
	return 1;	
}

