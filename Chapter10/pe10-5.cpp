// pe10-5.cpp - uses the customerStack class
// This is exercise 5 of chapter 10 in C++ Primer Plus by Stephen Prata
// questionFive.cpp is accompanied by customerStack.h and customerStack.cpp

#include<iostream>
#include "customerStack.h"

// to 

int main(void)
{
	// place using directives here
	using std::cin;
	using std::cout;
	using std::endl;

	// initialize our custumers
	customer Jimmy = {"Jimmy", 100};
	customer Timmy = {"Timmy", 39.50};
	customer Minny = {"Minny", 47.36};
	customer Vinny = {"Vinny", 18.01};

	cout << "We have four customers: " << endl;
	cout << Jimmy.fullname << ", paid $" 
		<< Jimmy.payment << endl;
	cout << Timmy.fullname << ", paid $" 
		<< Timmy.payment << endl;
	cout << Minny.fullname << ", paid $" 
		<< Minny.payment << endl;
	cout << Vinny.fullname << ", paid $" 
		<< Vinny.payment << endl;

	cout << "Let's push Jimmy" << endl;

	// push customers
	CustomerStack s;
	if (s.push(Jimmy))
		cout << Jimmy.fullname << " pushed successfully!"
		     << endl;
	else 
		cout << Jimmy.fullname << " not pushed successfully"
		     << endl;

	double total = 0.0;
	cout << "Here is our running total: $" << total << endl;

	cout << "Let's pop Jimmy" << endl;

	// pop customers
	customer c;
	if (s.pop(c))
	{
		cout << "Customer " << c.fullname << " popped."
		     << endl;
		total += c.payment;
	}
	else 
		cout << "No customers to pop" << endl;

	cout << "Let's pop another customer" << endl;
	
	// let's pop one last customer
	if (s.pop(c))
	{
		cout << "Customer " << c.fullname << " popped."
		     << endl;
		total += c.payment;
	}
	else 
		cout << "No customers to pop" << endl;

	cout << "Here is our new running total: $" << total
	     << endl;	

	return 0;
}

