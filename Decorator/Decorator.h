/*************************************************************************
    > File Name: Decorator.h
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sun 08 Feb 2015 04:03:38 PM CST
    > Function: 
    > Para:
 ************************************************************************/
#ifndef _DECORATOR_H_
#define _DECORATOR_H_

#include <iostream>
#include "Component.h"

using namespace std;

class Decorator:public Component
{
	public:
		virtual void Operation()=0;
};

class ConcreteDecorator:public Decorator
{
	public:
		ConcreteDecorator(Component *comp)
		{
			this->comp = comp;
		}

		void Operation()
		{
			comp->Operation();
			
			this->AddedBehaivorA();
		}

		void AddedBehaivorA()
		{
			cout<<"I'm added behaivor for concreteComponetA"<<endl;
		}

		void AddedBehaivorB()
		{
			cout<<"I'm added behavior for ConcreteComponetB"<<endl;
		}

	private:
		Component* comp;
};

#endif
