// pe5-3.cpp -- we compare simple interest at 10% vs compound interest at 5% with a $100 principle balance
// This is exercise 3 of chapter 5 in C++ Primer Plus by Stephen Prata

#include<iostream>


int main(void)
{
	using namespace std;
	double balance_simple, balance_compound, interest_simple, interest_compound;
	const int principle = 100;
	int years = 0;
	balance_simple = balance_compound = principle;

	// while loop in which interest accures and we count years as well as sums
	while (balance_compound <= balance_simple)
	{
		interest_simple = .10 * 100;
		balance_simple += interest_simple;
		interest_compound = .05 * balance_compound;
		balance_compound += interest_compound;
		years += 1;
	}

	cout << "After " << years << " years, the balance with compounding interest exceeds that of the simple interest balance" << endl;
	cout << "The compounding interest balance is $" << balance_compound << endl;
	cout << "The simple interest balance is $" << balance_simple << endl;
	
	return 0;
}


