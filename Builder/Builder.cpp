/*************************************************************************
    > File Name: Builder.cpp
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sat 07 Feb 2015 11:19:47 AM CST
    > Function: 
    > Para:
 ************************************************************************/
#include "Builder.h"


void GeneralControlBuilder::BuildTitle()
{
	Title *image_title = new ImageTitle();
	thisPage->AddFrame(image_title);
}

void GeneralControlBuilder::BuildButton()
{
	Button *image_button = new ImageButton();
	thisPage->AddFrame(image_button);
}

void GeneralControlBuilder::BuildToolBar()
{
	ToolBar *cell_toolbar = new CellToolBar();
	thisPage->AddFrame(cell_toolbar);
}

void  GeneralControlBuilder::BuildMenu()
{
	Menu* menu = new ListMenu();
	thisPage->AddFrame(menu);
}

void GeneralControlBuilder::BuildPage()
{
	thisPage = new SlidePage();

}

Page *GeneralControlBuilder::GetPage()
{
	return thisPage;
}

