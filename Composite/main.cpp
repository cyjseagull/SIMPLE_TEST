/*************************************************************************
    > File Name: main.cpp
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Mon 09 Feb 2015 10:49:32 AM CST
    > Function: 
    > Para:
 ************************************************************************/

#include <iostream>
using namespace std;
#include "Component.h"

template<class T>void delete_overload(T &object);
int main()
{
	MenuComponent *root = new MenuComposite();
	MenuComponent  *root_1 = new MenuComposite();
	MenuComponent *root_2 = new MenuComposite();
	MenuComponent *root_1_1 = new Leaf;
	MenuComponent *root_2_1 = new Leaf();
	MenuComponent *root_2_2 = new MenuComposite();
	MenuComponent *root_2_2_1 = new Leaf();

	root->SetName( (char*)"root");
	root_1->SetName( (char *)"root_1");
	root_2->SetName( (char *)"root_2");
	root_1_1->SetName( (char *)"root_1_1");
	root_2_1->SetName( (char *)"root_2_1");
	root_2_2->SetName((char *)"root_2_2");
	root_2_2_1->SetName((char *)"root_2_2_1");

	root->Add(root_1);
	root->Add(root_2);
	root_1->Add(root_1_1);
	root_2->Add(root_2_1);
	root_2->Add(root_2_2);
	root_2_2->Add(root_2_2_1);


	root->DisplayOperation(0);

	root->DeleteChild(root,(char *)"root_1_1");
	
	cout<<endl;
	root->DisplayOperation(0);

	delete_overload(root);
	delete_overload(root_1);
	delete_overload(root_2);
	delete_overload(root_1_1);
	delete_overload(root_2_1);
	delete_overload(root_2_2);
	delete_overload(root_2_2_1);
	
}

template<class T>void delete_overload(T &object )
{
	if(object)
	{
		delete object;
		object = NULL;
	}
}
