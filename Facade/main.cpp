/*************************************************************************
    > File Name: main.cpp
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Tue 10 Feb 2015 10:42:45 AM CST
    > Function: 
    > Para:
 ************************************************************************/

#include "Facade.h"

int main()
{
	Facade *f = new Facade();
	f->Operation1();
	f->Operation2();

	if(f)
	{
		delete f;
		f = NULL;
	}
}

