/*************************************************************************
    > File Name: Strategy.h
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Tue 10 Feb 2015 04:46:07 PM CST
    > Function: 
    > Para:
 ************************************************************************/
#ifndef _STRATEGY_H_
#define _STRATEGY_H_

#include <iostream>
using namespace std;



class Strategy
{
	public:
		virtual void OperationA()=0;
		virtual void OperationB()=0;

};

class ConcreteStrategyA:public Strategy
{
	public:
	  void OperationA()
	  {
			cout<<"step1 of concrete strategy A"<<endl;
	  }

	  void OperationB()
	  {
			cout<<"step2 of concrete strategy A"<<endl;
	  }
};

class ConcreteStrategyB:public Strategy
{	
	public:
		
		void OperationA()
		{
			cout<<"step1 of concrete strategy A"<<endl;
		}

		 void OperationB()
		{
			cout<<"step2 of concrete strategy A"<<endl;
		}
};


class Context
{
	public:
		Context(Strategy *a)
		{
			this->a=a;
		}
		
		~Context()
		{
			if(a)
			{
				delete a;
				a=NULL;
			}
		}


		void DoActionA()
		{
			if(a)
			{
				a->OperationA();
				a->OperationB();
			}
		}

	private:
		Strategy *a;

};
#endif

