/*************************************************************************
    > File Name: Facade.h
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Tue 10 Feb 2015 10:34:37 AM CST
    > Function: 
    > Para:
 ************************************************************************/

#ifndef _FACADE_H_
#define _FACADE_H_
#include "stdio.h"
#include <iostream>
using namespace std;


class SubSystem1
{
	public:
		void Operation1()
		{
			cout<<"subsystem 1 operation1"<<endl;
		}

		void Operation2()
		{
			cout<<"subsystem 1 operation 2"<<endl;
		}
};

class SubSystem2
{
	public:
		void Operation1()
		{
			cout<<"subsystem 2 operation 1"<<endl;
		}

		void Operation2()
		{
			cout<<"subsystem 2 operation 2"<<endl;
		}
};



class Facade
{
	public:
		Facade()
		{
			sys1 = new SubSystem1();
			sys2 = new SubSystem2();
		}

		~Facade()
		{
			if(sys1)
			{
				delete sys1;
				sys1 = NULL;
			}
			if(sys2)
			{
				delete sys2;
				sys2=NULL;
			}
		}

		void Operation1()
		{
			if(sys1)
				sys1->Operation1();
		}

		void Operation2()
		{
			if(sys2)
				sys2->Operation2();
		}

	private:
		SubSystem1 *sys1;
		SubSystem2 *sys2;
};
#endif
