/*************************************************************************
    > File Name: state.h
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sun 01 Mar 2015 09:28:54 AM CST
    > Function: 
    > Para:
	> classes: State,GoldState,RedState,SilverState
 ************************************************************************/
#ifndef _STATES_H_
#define _STATES_H_

#include <iostream>
#include "stdlib.h"
#include <typeinfo>
#include "string.h"
#include "context.h"

using namespace std;
class Account;

class States
{	
	public:
		Account* GetAccount();

		void SetAccount(Account* account);

		double GetBalance();

		void SetBalance(double balance);
		void Initialize(double interest,double lowerLimit,double upperLimit);
	
		virtual void Deposit(double amount);
		virtual void Withdraw(double amount);
		
		virtual void PayInterest();			

		virtual void CoConstructor(double balance,Account *account)
		{
		}

		virtual void PrintState()
		{
		};
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
		GoldState( States *state);
		GoldState(double balance,Account *account);	
		
		void CoConstructor(double balance,Account *account);
		void Deposit(double amount);
		
		void Withdraw(double amount);

		void PayInterest();
		
		
		void PrintState()
		{
			cout<<"GoldState"<<endl;
		}
	private:
		void StateChangeCheck();

};


class RedState:public States{
	public:
		RedState( States *state);
		RedState(double balance,Account *account);
		void CoConstructor(double balance,Account *account);

		void Deposit(double amount);
		void Withdraw(double amount);
		void PayInterest();
		void PrintState()
		{
			cout<<"RedState"<<endl;
		}
	private:
		void StateChangeCheck();
	private:
		double serviceFee;

};


class SilverState:public States
{
	public:	
		SilverState( States* state);
		SilverState(double balance,Account *account);
		void CoConstructor(double balance,Account *account);
		
		void PrintState()
		{
			cout<<"SilverState"<<endl;
		}
		void Deposit(double amount);
		void Withdraw(double amount);
		void PayInterest();

	private:
		void StateChangeCheck();
};


#endif
