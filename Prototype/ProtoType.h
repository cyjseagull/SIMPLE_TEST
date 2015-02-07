/*************************************************************************
    > File Name: Prototype_interface.h
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sat 07 Feb 2015 04:40:21 PM CST
    > Function: 
    > Para:
 ************************************************************************/
#ifndef _PROTOTYPE_INTERFACE_H_
#define _PROTOTYPE_INTERFACE_H_
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include <iostream>
using namespace std;

//interface of prototype
class PrototypeInterface
{
	public:

		 PrototypeInterface();

		virtual ~PrototypeInterface(){}

		virtual PrototypeInterface *Clone(){}		
		virtual void Show(){}
};


class ConcretePrototype: public PrototypeInterface
{
	public:
		//constructor
		ConcretePrototype(char *name);
		//copy constructor
		ConcretePrototype(const ConcretePrototype &r);
		~ConcretePrototype(){
			if(name)
			{	
  				delete name;
				name = NULL;
			}
		}

		//clone
		ConcretePrototype* Clone();

		void Show();

	protected:
		char *name;
};

#endif

