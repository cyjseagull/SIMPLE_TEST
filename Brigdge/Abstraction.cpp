/*************************************************************************
    > File Name: Abstraction.cpp
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sat 07 Feb 2015 08:47:50 PM CST
    > Function: 
    > Para:
 ************************************************************************/
#include "Abstraction.h"

RefinedAbstraction::RefinedAbstraction( Implementor *impl)
{
	abstract_impl = impl;
}


RefinedAbstraction::~RefinedAbstraction()
{
	delete abstract_impl;
}

void RefinedAbstraction::Operation()
{
	abstract_impl->Operation();
}
