// pe10-7.cpp - uses all features of the Plorg class
// This is exercise 7 of chapter 10 in C++ Primer Plus by Stephen Prata
// questionSeven.cpp is accompanied by plorg.h and plorg.cpp

#include<iostream>
#include "plorg.h"

int main(void)
{
	// declare using directives
	using std::cout;
	using std::endl;
	using std::cin;
	
	// initialize a Plorg object with default constructor
	cout << "Here is our default Plorg object" << endl;
	Plorg p1;
	p1.show();

	cout << "Enter a name for our next Plorg object: ";
	char name[30];
	cin.get(name, 30);
	cin.clear(); 	// clear error flag if nothing is entered
	while (cin.get() != '\n' && cin.eof() == 0)
		continue;
	cin.clear(); 	// if we reach EOF to reset error flags
	Plorg p2(name);
	cout << "Here is our new Plorg object" << endl;
	p2.show();

	// intiailze Plorg object with values given by user
	cout << "Enter a new CI value: ";
	int CI;
	while (!(cin >> CI))
	{
		cin.clear();
		while (cin.get() != '\n' && cin.eof() == 0)
			continue;
		cout << "Error. Not an integer." << endl;
		cout << "Enter a new CI value: ";
	}

	// change the CI value
	p2.changeCI(CI);
	
	// print object with new CI value
	cout << "Here is our new Plorg: " << endl;
	p2.show();

	cout << "Bye!" << endl;
	return 0;
}
