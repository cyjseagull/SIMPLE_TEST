/*************************************************************************
    > File Name: main.cpp
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sat 07 Feb 2015 05:01:01 PM CST
    > Function: 
    > Para:
 ************************************************************************/
#include "ProtoType.h"

int main()
{

	char str[255]="A";
	PrototypeInterface *r1 = new ConcretePrototype((char *)str);
	PrototypeInterface *r3 = r1->Clone();
	//r1->Show();
	r3->Show();

	if(r1)
	{
		delete r1;
		r1 = NULL;
	}
	if(r3)
	{
		delete r3;
		r3 = NULL;
	}
	return 0;
}


