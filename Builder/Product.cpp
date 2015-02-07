/*************************************************************************
    > File Name: Product.c
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sat 07 Feb 2015 10:29:27 AM CST
    > Function: 
    > Para:
 ************************************************************************/

#include "Product.h"

Page::Page()
{
	cout<<"create a page!"<<endl;
	frameList.clear();
}

Page::~Page()
{
	if(frameList.size())
	{
		std::list<Frame *>::iterator it;
		for(it = frameList.begin();it!=frameList.end(); it++)
		{
			frameList.erase(it);
			delete *it;
		}
	}
	
}

void Page::AddFrame(Frame *componet)
{	
	frameList.push_back(componet);
}

void Page::RemoveFrame(Frame *componet)
{
	std::list<Frame *>::iterator it;
	for(it=frameList.begin();it!=frameList.end();it++)
	{
		if(*it==componet)
		{		
			frameList.erase(it);
			delete componet;
			break;
		}
	}
}

void Page::draw()
{
	cout<<"page draw"<<endl;
	std::list<Frame *>::iterator it;
	for(it=frameList.begin() ; it!=frameList.end(); it++ )
	{
		(*it)->draw();
	}
}

uint64_t Page::GetFrameNum()
{
	return frameList.size();
}



