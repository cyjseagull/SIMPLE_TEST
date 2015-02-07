/*************************************************************************
    > File Name: Product.h
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sat 07 Feb 2015 10:06:59 AM CST
    > Function: 
    > Para:
 ************************************************************************/

#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <iostream>
#include "stdint.h"
#include <list>
#include <iterator>
using namespace std;

class Frame
{
	public:
		virtual void draw()=0;
};

/****************************************
 * title class
 * *************************************/
class Title:public Frame
{
	public:
		virtual void draw()
		{
			cout<<"draw title"<<endl;
		}	
};

class TextTitle:public Title
{		
	public:
		virtual void draw()
		{
			cout<<"draw text title"<<endl;
		}
};	

class ImageTitle:public Title
{
	public:
		virtual void draw()
		{
			cout<<"draw Image title"<<endl;
		}
};

/*********************************
 * menu class
 * *******************************/
class Menu:public Frame
{
	public:
		virtual void draw()
		{
			cout<<"draw menu"<<endl;
		}
};

class ListMenu:public Menu
{
	public:
		virtual void draw()
		{
			cout<<"draw list menu"<<endl;
		}
};

class ThreeMenu:public Menu
{
	public:
		virtual void draw()
		{
			cout<<"draw three menu"<<endl;
		}
};

/******************************************
 * ToolBar class
 * ****************************************/
class ToolBar:public Frame
{
	public:
		virtual void draw()
		{
			cout<<"draw toolbar"<<endl;
		}
};

class CellToolBar:public ToolBar
{
	public:
		virtual void draw()
		{
			cout<<"draw cell toolbar"<<endl;
		}
};

class FloatToolBar:public ToolBar
{
	public:
		virtual void draw()
		{
			cout<<"draw float toolbar"<<endl;
		}
};

/***************************************
 * button class
 * ***********************************/
class Button:public Frame
{
	public:
		virtual void draw(){
			cout<<"draw button"<<endl;
		}
};

class TextButton:public Button
{
	public:
		virtual void draw()
		{
			cout<<"draw text button"<<endl;
		}
};

class ImageButton:public Button
{
	public:
		virtual void draw()
		{
			cout<<"draw image button"<<endl;
		}
};

class ThreeButton:public Button
{
	public:
		virtual void draw()
		{
			cout<<"draw three button"<<endl;
		}
};

/***********************************
 * page class
 * **********************************/

class Page:public Frame
{
	public:
		Page();
		~Page();
		void AddFrame(Frame *componet);
		uint64_t GetFrameNum();
		virtual void draw();
		virtual void RemoveFrame(Frame *componet);
	private:
		std::list<Frame *> frameList;
};

class SlidePage:public Page
{
	public:
		virtual void draw()
		{
			Page::draw();
			cout<<"slidePage draw"<<endl;
		}
};
#endif
