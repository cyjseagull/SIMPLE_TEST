/*************************************************************************
    > File Name: main.cpp
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sun 08 Feb 2015 03:00:23 PM CST
    > Function: 
    > Para:
 ************************************************************************/

#include <iostream>
using namespace std;
#include "Target.h"
#include "Adaptee.h"

int main()
{
	Adaptee *adaptee = new Adaptee();
	Target *adapter = new Adapter(adaptee);
	adapter->Request();

	if(adaptee)
	{
		delete adaptee;
		adaptee=NULL;
	}

	if(adapter)
	{
		delete adapter;
		adapter=NULL;
	}
}
