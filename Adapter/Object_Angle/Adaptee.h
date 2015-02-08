/*************************************************************************
    > File Name: Adaptee.h
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sun 08 Feb 2015 02:57:48 PM CST
    > Function: 
    > Para:
 ************************************************************************/
#ifndef _ADAPTEE_H_
#define _ADAPTEE_H_

#include <iostream>
using namespace std;

class Adaptee
{
	public:
		Adaptee()
		{
			cout<<"I'm Adaptee"<<endl;
		}

		void SpercificRequest()
		{
			cout<<"I'm own service needed by Target"<<endl;
		}
};

#endif
