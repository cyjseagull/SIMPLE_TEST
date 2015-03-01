/*************************************************************************
    > File Name: main.cpp
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sun 01 Mar 2015 10:35:02 AM CST
    > Function: 
    > Para:
 ************************************************************************/

#include <iostream>
#include "string.h"
//#include "stdlib.h"
//#include <typeinfo>
#include "state.h"
#include "context.h"
using namespace std;


int main()
{

	Account *account = new Account((char *)("Yujie Chen"));
	account->Deposit(500);
	account->Deposit(300);
	account->Deposit(550);
	account->PayInterest();
	account->Withdraw(1100);
	account->Withdraw(2000);

	if(account)
	{
		delete account;
		account = NULL;
	}
	return 1;
}

/*class States
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

		virtual ~States()
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
		double lowerLimit;
		double upperLimit;
};

class GoldState:public States
{
	public:
		GoldState( States *state)
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
				account->SetState(dynamic_cast<States*>(new RedState(this)));
			else if(balance<lowerLimit)
			{
				account->SetState(dynamic_cast<States *>(new SilverState(this)));
			}
		}

};


class RedState:public States{
	public:
		RedState( States *state)
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
				account->SetState( (States*)(new SilverState(this)));
		}
	private:
		double serviceFee;

};


class SilverState:public States
{
	public:	
		SilverState( States* state)
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
				account->SetState(dynamic_cast<States*>(new RedState(this)));
			else if(balance>upperLimit)
			{
				account->SetState(dynamic_cast<States*>(new GoldState(this)));
			}
		}
};


class Account
{
	private:	
		States *state;
		char *owner;
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

		States* GetState()
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

		void SetState(States *state)
		{
			this->state = state;
		}
};*/
