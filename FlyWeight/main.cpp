/*************************************************************************
    > File Name: main.cpp
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Tue 10 Feb 2015 10:01:55 AM CST
    > Function: 
    > Para:
 ************************************************************************/
#include "FlyWeight.h"


void delete_object(FlyWeight *object);

int main()
{
	FlyWeightFactory* factory = new FlyWeightFactory();
	FlyWeight *f1= factory->GetFlyWeight(1);
	FlyWeight *f2= factory->GetFlyWeight(2);
	FlyWeight *f3= factory->GetFlyWeight(3);
	FlyWeight *f4= factory->GetFlyWeight(1);
	f1->Operation();
	f2->Operation();
	f3->Operation();
	f4->Operation();

	cout<<"pair size is:"<<factory->GetSize()<<endl;


	delete_object(f1);
	delete_object(f2);
	delete_object(f3);
	delete_object(f4);
	
	return 0;
}

void delete_object(FlyWeight *object)
{
	if(object)
	{
		delete object;
		object = NULL;
	}
}

