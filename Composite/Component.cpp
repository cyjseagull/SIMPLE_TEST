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

bool MenuComposite::Remove(char *name,std::list<MenuComponent *> &children_list)
{
	std::list<MenuComponent *>::iterator it;
	if( !children_list.empty() )
	{
		for( it = children_list.begin();it!=children_list.end();it++)
		{	
			if(!strcmp( name, (*it)->GetName()))
			{
				cout<<"name:"<<name<<endl;
				children_list.erase(it);
				break;
			}
		}
	}
}

bool MenuComposite::Remove(MenuComponent* current_node, char *name ,MenuComponent* &child)
{
	std::list<MenuComponent *>::iterator it;

	std::list<MenuComponent *>::iterator it2;
	bool rv = false;	
	if(!strcmp(current_node->GetName(),name))
	{
		cout<<"found it"<<endl;
		
		cout<<"child->name:"<<current_node->GetName()<<endl;
		child = current_node;	
		cout<<"parent:"<<current_node->parent->GetName()<<endl;
		rv = true;
	}

	if (!rv)
	{
		for(it= current_node->children.begin(); it!= current_node->children.end();it++)
		{		
			Remove(*it,name,child);
		}
	}
	if(rv&& (it ==current_node->children.end()))
	return rv;

	return rv;
}




bool MenuComposite::DeleteChild(MenuComponent *node,char *name)
{
	bool rv = false;
	MenuComponent *child=NULL;
	std::list<MenuComponent *>::iterator it;
	
	if(Remove(node,name,child))
	{	
		if( !(child->children.empty()) )
		{
			for( it = (child->children).begin(); it!=child->children.end();it++)		{
				cout<<(*it)->GetName()<<endl;
				(*it)->parent= child->parent;
				child->parent->children.push_back(*it);
			}
		}	
		cout<<"parent children num:"<<child->parent->children.size()<<endl;
		child->parent->children.remove(child);
		
		cout<<"parent children num2:"<<child->parent->children.size()<<endl;
		
		delete child;	
		rv = true;
}
	cout<<"oh no!"<<endl;
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
		(*it)->DisplayOperation(depth+4);	
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
