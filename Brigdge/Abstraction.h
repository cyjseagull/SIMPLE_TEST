/*************************************************************************
    > File Name: Abstraction.h
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sat 07 Feb 2015 08:40:21 PM CST
    > Function: 
    > Para:
 ************************************************************************/
#ifndef _ABSTRACTION_H_
#define _ABSTRACTION_H_
#include <iostream>
#include "Implement.h"
using namespace std;

class Abstraction
{
	public:
		virtual void Operation()=0;

};

class RefinedAbstraction:public Abstraction
{
	public:
		RefinedAbstraction(Implementor * );
		~RefinedAbstraction();
		
		void Operation();
	private:
		Implementor *abstract_impl;

};

#endif

