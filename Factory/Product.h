/*************************************************************************
    > File Name: Product.h
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Fri 06 Feb 2015 08:52:06 PM CST
    > Function: 
    > Para:
 ************************************************************************/
#ifndef _PRODUCT_H_
#define _PRODUCT_H_

class Product
{
	public:
		virtual ~Product()=0;
	protected:
		Product();
	private:
};

class ConcreteProduct:public Product
{
	public:
		~ConcreteProduct();
		concreteProduct();	
};

#endif

