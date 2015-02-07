/*************************************************************************
    > File Name: main.cpp
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sat 07 Feb 2015 11:36:23 AM CST
    > Function: 
    > Para:
 ************************************************************************/

#include <iostream>
#include "Director.h"
#include "Product.h"
#include "Builder.h"


using namespace std;

int main()
{
	Page *page;

	ControlBuilder *tmp_builder;
	tmp_builder = new GeneralControlBuilder;

	PageDirector *page_director = new PageDirector( tmp_builder);
	page = page_director->CreatePage();
	page->draw();
//	delete page_director;
	return 1;
}

