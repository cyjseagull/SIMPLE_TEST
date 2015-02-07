/*************************************************************************
    > File Name: Prototype_interface.cpp
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sat 07 Feb 2015 04:49:45 PM CST
    > Function: 
    > Para:
 ************************************************************************/
#include "ProtoType.h"

PrototypeInterface::PrototypeInterface()
{

}

//constructor
ConcretePrototype::ConcretePrototype( char *name )
{
	if(name)
	{
		this->name = new char[strlen(name)+1];
		memcpy(this->name,name,strlen(name));
		name[strlen(name)]='\0';
	}
	else
	{
		this->name = new char[1];
		name[0]='\0';
	}
}

//copy constructor
ConcretePrototype::ConcretePrototype( const ConcretePrototype &r )
{
	int tmp = strlen(r.name);
	name = new char[tmp+1];
	memcpy(name,r.name,tmp);
}

//clone object
ConcretePrototype * ConcretePrototype::Clone()
{
	return new ConcretePrototype(*this);
}

void ConcretePrototype::Show()
{
	cout<<"name of ConcreteType: "<< name<<endl;
}

