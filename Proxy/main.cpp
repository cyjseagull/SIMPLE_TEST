/*************************************************************************
    > File Name: main.cpp
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Tue 10 Feb 2015 02:58:04 PM CST
    > Function: 
    > Para:
 ************************************************************************/
#include "Subject.h"

int main()
{
	Subject *proxy = new Proxy();
	proxy->Request();
	if(proxy)
	{
		cout<<"delete proxy!"<<endl;
		delete proxy;
		proxy=NULL;
	}
	return 1;
}
