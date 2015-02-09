/*************************************************************************
    > File Name: Component.h
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Mon 09 Feb 2015 09:01:24 AM CST
    > Function: 
    > Para:
 ************************************************************************/

#ifndef _COMPONENT_H_
#define _COMPONENT_H_
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include <list>
#include <iterator>
#include <iostream>
using namespace std;

class MenuComponent
{
	public:
		MenuComponent()
		{
			name = NULL;
			url = NULL;
		}

		MenuComponent( char *name,char *url)
		{
			Copy(this->name,name);
			Copy(this->url,url);
		}
		virtual ~MenuComponent()
		{
			if(name)
			{
				delete name;
				name = NULL;
			}
			if(url)
			{
				delete url;
				url = NULL;
			}
		}

		virtual void DisplayOperation(int depth){
		}
		virtual bool Add(MenuComponent *name){
		}
		virtual bool Remove(char *name,MenuComponent * & ){
		}
		virtual bool DeleteChild(char *name){

		}
		virtual char* GetName()
		{
			return name;
		}
		virtual void SetName(char *name)
		{	
			this->Copy(this->name,name);

		}

		virtual char* GetUrl()
		{
			return url;
		}

		virtual void SetUrl(char *url)
		{
			this->Copy(this->url,url);
		}

		void Copy(char* &des,char *source)
		{
			int len = 0;
			if(source)
			{
				len = strlen(source);
			//	cout<<len<<endl;
				des = new char[len+1];
				memcpy(des,source,len);
				des[len]='\0';
			}
		}
	
		MenuComponent *parent;
		std::list<MenuComponent *> children;
	private:
		char *name;
		char *url;
};


class MenuComposite:public MenuComponent
{
	public:
		MenuComposite();
	    virtual	~MenuComposite();
		virtual void DisplayOperation(int depth);
		virtual bool Add(MenuComponent *menu);
		virtual bool Remove(char *name, MenuComponent* &);
		virtual bool DeleteChild(char *name);
		virtual bool GetChildren(std::list<MenuComponent*>& children);
		virtual bool SetChidren(std::list<MenuComponent *> children);
		virtual bool SearchChild(MenuComponent *des_child ,char *name);

	private:
		std::list<MenuComponent *> children;
		MenuComponent *parent;
};


class Leaf:public MenuComponent
{
	public:
		void DisplayOperation(int depth);
};

#endif
