/*************************************************************************
    > File Name: Main.cpp
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sat 07 Feb 2015 08:58:55 AM CST
    > Function: 
    > Para:
 ************************************************************************/

#include <iostream>
using namespace std;
#include "Singleton.h"


int main()
{
	Singleton *sgn = Singleton::Instance();

	return 0;
}
