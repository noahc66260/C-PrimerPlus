// BankAccount.h - This is the header file which contains the BankAccount class
// This is exercise 1 of chapter 10 in C++ Primer Plus by Stephen Prata
// This file is accompanied by BankAccount.cpp and questionOne.cpp

#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_

#include<iostream>

class BankAccount
{
private:
	std::string name;
	std::string account;
	double balance;
public:
	BankAccount(std::string name, std::string account, 
		double balance= 0.0);
	void printAccount(void) const;
	void deposit(double sum);
	void withdraw(double sum);
};

#endif
