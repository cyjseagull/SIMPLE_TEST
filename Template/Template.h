/*************************************************************************
    > File Name: Template.h
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Tue 10 Feb 2015 03:47:29 PM CST
    > Function: 
    > Para:
 ************************************************************************/
#ifndef _TEMPLATE_H_
#define _TEMPLATE_H_
#include <iostream>
using namespace std;

//abstract interface of classes with same Framework but no same complement;
class AbstractClass
{
	public:
		virtual void Operation1()=0;
		virtual void Operation2()=0;
		//template method
		virtual void TemplateMethod()
		{
			this->Operation1();
			this->Operation2();

		}
};

class ConcreteClass1:public AbstractClass
{
	public:
		void Operation1()
		{
			cout<<"step one of concrete class 1"<<endl;
		}

		void Operation2()
		{
			cout<<"step two of concrete class 1"<<endl;
		}
};

class ConcreteClass2:public AbstractClass
{
	public:

		void Operation1()
		{
			cout<<"step one of concrete class 2"<<endl;
		}

		void Operation2()
		{
			cout<<"step two of concrete class 2"<<endl;
		}
};


#endif

