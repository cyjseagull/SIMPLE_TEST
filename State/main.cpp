/*************************************************************************
    > File Name: main.cpp
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sun 01 Mar 2015 10:35:02 AM CST
    > Function: 
    > Para:
 ************************************************************************/

#include <iostream>
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
}
