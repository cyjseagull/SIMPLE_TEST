/*************************************************************************
    > File Name: context.h
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sun 01 Mar 2015 10:05:47 AM CST
    > Function: 
    > Para:
 ************************************************************************/

#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include <iostream>
#include "string.h"
#include "stdlib.h"
#include <typeinfo>
#include "state.h"
using namespace std;
class States;
class Account
{
	private:	
		States *state;
		char *owner;
	public:
		Account(char *owner);
	//	Account(char *owner,States* curState);
		~Account();
		States* GetState();
		void Withdraw(double amount);
		void Deposit(double amount);
		void PayInterest();
		void SetState(States *state);
};
#endif
