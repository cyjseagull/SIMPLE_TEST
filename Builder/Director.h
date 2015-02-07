/*************************************************************************
    > File Name: Director.h
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sat 07 Feb 2015 11:31:31 AM CST
    > Function: 
    > Para:
 ************************************************************************/
#ifndef _DIRECTOR_H_
#define _DIRECTOR_H_

#include <iostream>
#include "Builder.h"
using namespace std;

class PageDirector
{
	public:
		
		PageDirector(ControlBuilder *tmp_builder ){

			cout<<"create page director"<<endl;
			m_builder = tmp_builder;
		}

		virtual Page *CreatePage()
		{
			
			m_builder->BuildPage();
			m_builder->BuildTitle();
			m_builder->BuildButton();
			m_builder->BuildMenu();
			m_builder->BuildToolBar();

			return m_builder->GetPage();
		}
	private:
		ControlBuilder *m_builder;
};

#endif

