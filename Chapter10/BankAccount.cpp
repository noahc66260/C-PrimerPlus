// BankAccount.cpp - The implementation of the BankAccount class
// This is exercise 1 of chapter 10 in C++ Primer Plus by Stephen Prata
// This file is accompanied by BankAccount.h and questionOne.cpp

#include<iostream>
#include "BankAccount.h"

BankAccount::BankAccount(std::string name, std::string account, 
	double balance)
{
	using std::cout;
	using std::endl;

	this->name = name;
	this->account = account;

	if (balance >= 0)
		this->balance = balance;
	else
	{
		cout << "You can't have a negative balance.";
		cout << endl << "Setting balance to 0.";
		cout << endl;
		this->balance = 0.0;
	}
}

void BankAccount::printAccount(void) const
{
	using std::cout;
	using std::endl;
	
	cout << "Name: " << name << endl;
	cout << "Account #: " << account << endl;
	cout << "Balance: " << balance << endl;
}

void BankAccount::deposit(double sum)
{
	using std::cout;
	using std::endl;

	if (sum < 0)
	{
		cout << "You can't deposit negative money" << endl;
		cout << "Deposit aborted" << endl;
	}
	else
		balance += sum;
}

void BankAccount::withdraw(double sum)
{
	using std::cout;
	using std::endl;

	if (sum <= balance && sum >= 0)
		balance -= sum;
	else if (sum < 0)
	{
		cout << "You can't withdraw negative money" << endl;
		cout << "Withdrawal aborted" << endl;
	}
	else if (sum > balance)
	{
		cout << "You can't withdraw more than you have";
		cout << endl << "Withdrawal aborted" << endl;
	}
}


