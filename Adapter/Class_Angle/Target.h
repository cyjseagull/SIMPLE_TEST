/*************************************************************************
    > File Name: Target.h
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sun 08 Feb 2015 02:49:29 PM CST
    > Function: 
    > Para:
 ************************************************************************/
#ifndef _TARGET_H_
#define _TARGET_H_

#include "Adaptee.h"
#include <iostream>
using namespace std;


class Target
{
	public:
		virtual void Request()=0;

};


class Adapter:public Target,private Adaptee
{
	public:
		Adapter()
		{}


		~Adapter()
		{}	
		
		void Request()
		{
			this->SpercificRequest();
		}


};

#endif
