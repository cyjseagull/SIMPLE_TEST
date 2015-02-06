/*************************************************************************
    > File Name: Factory_Interface.cpp
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Fri 06 Feb 2015 08:44:54 PM CST
    > Function: 
    > Para:
 ************************************************************************/

#ifndef _FACTORY_H_
#define _FACTORY_H_
#include "Product.h"


class Factory
{
	public:
		virtual ~Factory()=0;
		virtual Product* CreateProduct()=0;
	protected:
		Factory();
	private:

};

class ConcreteFactory:Factory
{
public:
	~ConcreteFactory();
	ConcreteFactory();
	Product *CreateProduct();

};

#endif
