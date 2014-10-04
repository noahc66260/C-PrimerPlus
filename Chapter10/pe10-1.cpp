// pe10-1.cpp - uses the BankAccount class
// This is exercise 1 of chapter 10 in C++ Primer Plus by Stephen Prata
// This file is accompanied by BankAccount.h and BankAccount.cpp

#include<iostream>
#include "BankAccount.h"

int main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;

	BankAccount checking("Jerry", "2104032405", 2000.00);
	cout << "Here is our account: " << endl;
	checking.printAccount();
	cout << "Now we deposit $100" << endl;
	checking.deposit(100);
	checking.printAccount();
	cout << "And now we withdraw $1500" << endl;
	checking.withdraw(1500);
	checking.printAccount();
	cout << "Now let's try some illegal operations" << endl;
	cout << "Let's deposit $-200" << endl;
	checking.deposit(-200);
	checking.printAccount();
	cout << "Let's withdraw $-500" << endl;
	checking.withdraw(-500);
	checking.printAccount();
	cout << "Finally let's withdraw $10,000" << endl;
	checking.withdraw(10000);
	checking.printAccount();

	cout << "Let's try to initialize a saving's account "
		<< "with a negative balance" << endl;
	BankAccount savings("Jerry", "1423540433", -1000);
	savings.printAccount();

	cout << "Bye!" << endl;

}
