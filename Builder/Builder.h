/*************************************************************************
    > File Name: Builder.h
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sat 07 Feb 2015 10:50:57 AM CST
    > Function: 
    > Para:
 ************************************************************************/
#ifndef _BUILDER_H_
#define _BUILDER_H_
#include <iostream>
#include "Product.h"

using namespace std;



class ControlBuilder
{
	public:
		virtual void BuildTitle()
		{
		};
		virtual void BuildButton(){

		};
		virtual void BuildToolBar(){

		};
		virtual void BuildPage(){

		};
		virtual void BuildMenu(){

		};

		virtual Page* GetPage(){
			return NULL;
		}
	
};

class GeneralControlBuilder:public ControlBuilder
{
	public:
	//	GeneralControlBuilder();
		virtual void BuildTitle();
		virtual void BuildButton();
		virtual void BuildMenu();
		virtual void BuildToolBar();
		virtual void BuildPage();
		virtual Page* GetPage();
	private:
		Page* thisPage;
};
#endif
