/*************************************************************************
    > File Name: state.h
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sun 01 Mar 2015 09:28:54 AM CST
    > Function: 
    > Para:
	> classes: State,GoldState,RedState,SilverState
 ************************************************************************/

#include "state.h"

	
		Account* States::GetAccount()
		{
			return this->account;
		}

		void States::SetAccount(Account* account)
		{
			this->account = account;
		}

		double States::GetBalance()
		{
			return this->balance;
		}

		void States::SetBalance(double balance)
		{
			this->balance = balance;
		}

		void States::Initialize(double interest,double lowerLimit,double upperLimit)
		{
			this->interest = interest;
			this->lowerLimit = lowerLimit;
			this->upperLimit = upperLimit;
		}
	
		void States::Deposit(double amount)
		{
		//	cout<<"state deposit"<<endl;
			this->balance += amount;
		}
		void States::Withdraw(double amount)
		{
		}
		
		void States::PayInterest()
		{
		}	

void GoldState::CoConstructor(double balance,Account *account)
{
	
			this->balance = balance;
			this->account =account;
			Initialize(0.05,1000,10000000);
}


GoldState::GoldState(double balance,Account *account)
{
	CoConstructor(balance,account);
}


GoldState::GoldState( States *state)
		{
			CoConstructor(state->balance,state->account);
				
		}
		
		void GoldState::Deposit(double amount)
		{
		//	cout<<"gold deposit"<<endl;
			this->balance += amount;
			StateChangeCheck();
		}
		
		void GoldState::Withdraw(double amount)
		{
			this->balance -= amount;
			StateChangeCheck();
		}

		void GoldState::PayInterest()
		{
		//	cout<<"pay gold interest"<<endl;
			balance += interest*balance;
			StateChangeCheck();
		}

		void GoldState::StateChangeCheck()
		{
			if(balance < 0)
				account->SetState(new RedState(this));
			else if(balance<lowerLimit)
			{
				account->SetState(new SilverState(this));
			}
		}



void RedState::CoConstructor(double balance,Account *account)
{
	
			this->balance = balance;
			this->account =account;
			Initialize(0.05,1000,10000000);	
			this->serviceFee = 15;
}

RedState::RedState( States *state)
		{
			CoConstructor(state->balance,state->account);
		}

RedState::RedState(double balance,Account *account)
{
	CoConstructor(balance,account);
}
		
		void RedState::Deposit(double amount)
		{
		//	cout<<"red deposit"<<endl;
			this->balance += amount;
			StateChangeCheck();
		}
		
		void RedState::Withdraw(double amount)
		{
			amount -= serviceFee;
			cout<<"sorry,this account has no balance to withdraw!"<<endl;
		}

		void RedState::PayInterest()
		{
		}


		void RedState::StateChangeCheck()
		{
			if(balance >upperLimit )
				account->SetState(new SilverState(this));
		}


void SilverState::CoConstructor(double balance,Account *account)
{
	
			this->balance = balance;
			this->account =account;
			Initialize(0,0,1000);
}

SilverState::SilverState(double balance,Account *account)
{
	CoConstructor(balance,account);
}
SilverState::SilverState( States* state)
		{
				CoConstructor(state->balance,state->account);
		}
		
		void SilverState::Deposit(double amount)
		{
//			cout<<"silver deposit"<<endl;
			this->balance += amount;	
			StateChangeCheck();
		}
		
		void SilverState::Withdraw(double amount)
		{
			this->balance -= amount;
			StateChangeCheck();
		}

		void SilverState::PayInterest()
		{
			balance += interest*balance;
			StateChangeCheck();
		}


		void SilverState::StateChangeCheck()
		{
				
			if(balance < lowerLimit)
				account->SetState(new RedState(this));
			else if(balance>upperLimit)
			{		
				account->SetState(new GoldState(this));
			}
		}
