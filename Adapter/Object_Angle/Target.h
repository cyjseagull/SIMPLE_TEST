/*************************************************************************
    > File Name: Target.h
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sun 08 Feb 2015 02:49:29 PM CST
    > Function: 
    > Para:
 ************************************************************************/
#ifndef _TARGET_H_
#define _TARGET_H_

#include "Adaptee.h"
#include <iostream>
using namespace std;


class Target
{
	public:
		virtual void Request()=0;

};


class Adapter:public Target
{
	public:
		Adapter(Adaptee* adaptee)
		{
			if(adaptee)
				m_adaptee=adaptee;
			else 
				m_adaptee = NULL;
		}


		~Adapter()
		{
			if(m_adaptee)
			{
				delete m_adaptee;
				m_adaptee = NULL;
			}
		}	
		
		void Request()
		{
		 cout<<"request of class Target:"<<endl;
		  if(m_adaptee)
			m_adaptee->SpercificRequest();
		  else
			  cout<<"no initialize data member m_adaptee"<<endl;
		}


	private:
		Adaptee* m_adaptee;

};

#endif
