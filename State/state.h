/*************************************************************************
    > File Name: state.h
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sun 01 Mar 2015 09:28:54 AM CST
    > Function: 
    > Para:
	> classes: State,GoldState,RedState,SilverState
 ************************************************************************/
#ifndef _STATE_H_
#define _STATE_H_

#include <iostream>
#include "context.h"
using namespace std;

class State
{
	public:
		Account* GetAccount()
		{
			return this->account;
		}

		void SetAccount(Account* account)
		{
			this->account = account;
		}

		double GetBalance()
		{
			return this->balance;
		}

		void SetBalance(double balance)
		{
			this->balance = balance;
		}

		void Initialize(double interest,double lowerLimit,double upperLimit)
		{
			this->interest = interest;
			this->lowerLimit = lowerLimit;
			this->upperLimit = upperLimit;
		}
	
		virtual void Deposit(double amount)
		{
			this->balance += amount;
		}
		virtual void Withdraw(double amount)
		{
		}
		
		virtual void PayInterest()
		{
		}

		virtual ~State()
		{
			if(account)
			{
				delete account;
				account = NULL;
			}
		}

	public:
		Account *account;
		double interest;
		double balance;

	protected:
		double lowerLimit;
		double upperLimit;
};


class GoldState:public State
{
	public:
		GoldState( State *state)
		{
			this->balance = state->GetBalance();
			this->account = state->GetAccount();
			Initialize(0.05,1000,10000000);
		}
		
		void Deposit(double amount)
		{
			this->balance += amount;
			StateChangeCheck();
		}
		
		void Withdraw(double amount)
		{
			this->balance -= amount;
			StateChangeCheck();
		}

		void PayInterest()
		{
			balance += interest*balance;
			StateChangeCheck();
		}

	private:
		void StateChangeCheck()
		{
			if(balance < 0)
				account->SetState(dynamic_cast<State*>(new RedState(this)));
			else if(balance<lowerLimit)
			{
				account->SetState(dynamic_cast<State *>(new SilverState(this)));
			}
		}

};

class RedState:public State
{
	public:
		RedState( State *state)
		{
			this->balance = state->GetBalance();
			this->account = state->GetAccount();
			Initialize(0,-100,0);
			this->serviceFee = 15;
		}
		
		void Deposit(double amount)
		{
			this->balance += amount;
			StateChangeCheck();
		}
		
		void Withdraw(double amount)
		{
			amount -= serviceFee;
			cout<<"sorry,this account has no balance to withdraw!"<<endl;
		}

		void PayInterest()
		{
		}

	private:
		void StateChangeCheck()
		{
			if(balance >upperLimit )
				account->SetState( (State*)(new SilverState(this)));
		}
	private:
		double serviceFee;

};

class SilverState:public State
{
	public:	
		SilverState( State* state)
		{
			this->balance = state->GetBalance();
			this->account = state->GetAccount();
			Initialize(0,0,1000);
		}
		
		void Deposit(double amount)
		{
			this->balance += amount;
			StateChangeCheck();
		}
		
		void Withdraw(double amount)
		{
			this->balance -= amount;
			StateChangeCheck();
		}

		void PayInterest()
		{
			balance += interest*balance;
			StateChangeCheck();
		}

	private:
		void StateChangeCheck()
		{
			if(balance < lowerLimit)
				account->SetState(dynamic_cast<State*>(new RedState(this)));
			else if(balance>upperLimit)
			{
				account->SetState(dynamic_cast<State *>(new GoldState(this)));
			}
		}
};


#endif
