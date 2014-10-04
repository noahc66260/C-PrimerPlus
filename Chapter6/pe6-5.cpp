// pe6-5.cpp -- calculates taxes based on income of tvarps
// This is exercise 5 of chapter 6 in C++ Primer Plus by Stephen Prata

#include<iostream>
const double first5000 = 0.0;
const double next10000 = .10;
const double next20000 = .15;
const double after35000 = .20;

int main(void)
{
	using namespace std; 

	// prompt user
	cout << "Please enter the number of tvarps you earned this year." << endl
	     << "Enter a negative number to quit: "; 
	double tvarps;
	cin >> tvarps;

	// calculate taxes 
	double taxes = 0;
	while (tvarps >= 0)
	{
		if (tvarps >= 35000)
			taxes = 5000 * first5000 + 10000 * next10000 + 20000 * next20000 + (tvarps - 35000) * after35000;
		else if (tvarps >= 15000)
			taxes = 5000 * first5000 + 10000 * next10000 + (tvarps - 15000) * next20000;
		else if (tvarps >= 5000)
			taxes = 5000 * first5000 + (tvarps - 5000) * next10000;
		else
			taxes = (5000 - tvarps) * first5000;

		// reprompt user
		cout << "You owe " << taxes << " tvarps in taxes" << endl
		     << "Enter a new income or a negative number to quit: "; 
		cin >> tvarps;
	}
	
	return 0;
}
