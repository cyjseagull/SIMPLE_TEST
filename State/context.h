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
#include "state.h"
#include "string.h"
#include "stdlib.h"
#include <typeinfo>
using namespace std;

class Account
{
	public:
		Account(char *owner)
		{
			int len = strlen(owner);
			this->owner = new char[len];
			if(this->owner)
			{
				memcpy(this->owner,owner,len);
				this->owner[len]='\0';
			}	

		}

		~Account()
		{
			if(owner)
			{
				delete owner;
				owner = NULL;
			}
			if(state)
			{
				delete state;
				state = NULL;
			}
		}

		State* GetState()
		{
			return this->state;
		}

		void Withdraw(double amount)
		{
			state->Withdraw(amount);
			cout<<"==============================================="<<endl;
			cout<<"="<<owner<<" withdraw "<<amount<<endl;
			cout<<"="<<owner<<"balance = "<<state->GetBalance()<<endl;
			cout<<"="<<owner<<" status= " <<typeid(state).name()<<endl;
			cout<<"==============================================="<<endl;
		}

		void Deposit(double amount)
		{
			state->Deposit(amount);
			cout<<"==============================================="<<endl;
			cout<<"="<<owner<<" deposit "<<amount<<endl;
			cout<<"="<<owner<<"balance = "<<state->GetBalance()<<endl;
			cout<<"="<<owner<<" status= "<<typeid(state).name()<<endl;
			cout<<"==============================================="<<endl;
		}

		void PayInterest()
		{
			state->PayInterest();
			cout<<"==============================================="<<endl;
			cout<<"="<<owner<<" interest paid "<<endl;
			cout<<"="<<owner<<"balance = "<<state->GetBalance()<<endl;
			cout<<"="<<owner<<" status= "<<typeid(state).name()<<endl;
			cout<<"==============================================="<<endl;
		}

		void SetState(State *state)
		{
			this->state = state;
		}
	
	private:
		char *owner;
		State *state;
};
#endif
