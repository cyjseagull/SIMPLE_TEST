/*************************************************************************
    > File Name: context.h
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sun 01 Mar 2015 10:05:47 AM CST
    > Function: 
    > Para:
 ************************************************************************/

#include "context.h"


Account::Account(char *owner)
		{
			
			int len = strlen(owner);
			this->owner = new char[len];	
			if(this->owner)
			{ 
				memcpy(this->owner,owner,len);
				this->owner[len]='\0';
			}	
			this->state = new SilverState(0,this);
		}

/*Account::Account(char *owner,States* state)
		{
			
			Account(owner);
			this->state = state;
		}*/

Account::~Account()
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

		States* Account::GetState()
		{
			return this->state;
		}

		void Account::Withdraw(double amount)
		{
			state->Withdraw(amount);
			cout<<"==============================================="<<endl;
			cout<<"=  "<<owner<<" withdraw "<<amount<<endl;
			cout<<"=  "<<owner<<" balance = "<<state->GetBalance()<<endl;
			cout<<"=  ";
			state->PrintState();
			cout<<"==============================================="<<endl;
			cout<<endl;
		}

		void Account::Deposit(double amount)
		{
		
			state->Deposit(amount);
			cout<<"==============================================="<<endl;
			cout<<"=  "<<owner<<" deposit "<<amount<<endl;
			cout<<"=  "<<owner<<" balance = "<<state->GetBalance()<<endl;
			cout<<"=  ";
			state->PrintState();
			cout<<"==============================================="<<endl;
			cout<<endl;
		}

		void Account::PayInterest()
		{
			state->PayInterest();
			cout<<"==============================================="<<endl;
			cout<<"=  "<<owner<<" interest paid "<<endl;
			cout<<"=  "<<owner<<" balance = "<<state->GetBalance()<<endl;
			cout<<"=  ";
			state->PrintState();
			cout<<"==============================================="<<endl;
			cout<<endl;
		}

		void Account::SetState(States *state)
		{	
			if(this->state)
			{
				delete this->state;
				this->state = NULL;
			}
			this->state = state;
		}
