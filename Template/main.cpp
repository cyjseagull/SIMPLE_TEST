/*************************************************************************
    > File Name: main.cpp
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Tue 10 Feb 2015 03:53:50 PM CST
    > Function: 
    > Para:
 ************************************************************************/
#include "Template.h"
#include <typeinfo>

template<class T>
void DelObject(T a);
int main()
{
	AbstractClass *a1=new ConcreteClass1();
	AbstractClass *a2=new ConcreteClass2();


	a1->TemplateMethod();
	a2->TemplateMethod();

	DelObject(a1);
	DelObject(a2);

}

template<class T>
void DelObject(T a)
{
	if(a)
	{
		cout<<"delete object: "<<typeid(a).name()<<endl;
		delete a;
		a = NULL;
	}
}


