/*************************************************************************
    > File Name: Component.cpp
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Mon 09 Feb 2015 09:46:42 AM CST
    > Function: 
    > Para:
 ************************************************************************/
#include "Component.h"

MenuComposite::MenuComposite()
{
	children.clear();
	parent = NULL;
}


MenuComposite::~MenuComposite()
{
	std::list<MenuComponent *>::iterator it;
	if(children.size())
	{
		for(it = children.begin();it!=children.end();it++)
		{
			(*it)->parent = this->parent;
		}
		children.clear();
	}
}

bool MenuComposite::Add ( MenuComponent* menu)
{
//	cout<<"push children"<<endl;
	children.push_back(menu);
	menu->parent = this;
	cout<<this->GetName()<<"'s child size:"<<this->children.size()<<endl;
	return true;
}

bool MenuComposite::Remove( char *name ,MenuComponent* &child)
{
	std::list<MenuComponent *>::iterator it;
	bool rv = false;
	for(it=children.begin(); it!=children.end();it++)
	{		
		if( !strcmp((*it)->GetName(),name))
		{	
		//	cout<<(*it)->GetName()<<endl;
			child = *it;
		//	children.erase(it);
			rv =true;
			break;
		}
	}
	return rv;
}

bool MenuComposite::DeleteChild(char *name)
{
	bool rv = false;
	MenuComponent *child=NULL;
	std::list<MenuComponent *>::iterator it;
	
	if(Remove(name,child))
	{	
		if( !(child->children.empty()) )
		{
			for( it = (child->children).begin(); it!=child->children.end();it++)		{
				cout<<(*it)->GetName()<<endl;
				(*it)->parent= child->parent;
				child->parent->children.push_back(*it);
			}
			delete child;
			rv = true;
		}
	}
	return rv;
}


bool MenuComposite::GetChildren(std::list<MenuComponent *>& children)
{
	children = this->children;
	return true;
}

bool MenuComposite::SetChidren(std::list<MenuComponent *> children)
{
	this->children = children;
	return true;
}

bool MenuComposite::SearchChild(MenuComponent *des_chid,char *name)
{

	return true;
}

void MenuComposite::DisplayOperation(int depth)
{
	for(int i=0;i<depth;i++)
		cout<<"-";

	cout<<GetName()<<endl;
	
	std::list<MenuComponent *>::iterator it;
	for(it=children.begin();it!=children.end();it++)
	{
		(*it)->DisplayOperation(depth+2);	
	}

}

void Leaf::DisplayOperation(int depth)
{
	for(int i=0;i<depth;i++)
	{
		cout<<"-";
	}
	cout<<GetName()<<endl;
}
