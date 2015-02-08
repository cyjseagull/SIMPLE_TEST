/*************************************************************************
    > File Name: main.cpp
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sun 08 Feb 2015 04:20:33 PM CST
    > Function: 
    > Para:
 ************************************************************************/

#include <iostream>
using namespace std;
#include  "Decorator.h"
#include "Component.h"

int main()
{
	Component *comp1 = new ConcreteComponentA();
	Decorator *decorator = new ConcreteDecorator(comp1);

	decorator->Operation();


	if(comp1)
	{
		delete comp1;
		comp1 = NULL;
	}

	if(decorator)
	{
		delete decorator;
		decorator = NULL;
	}
}
