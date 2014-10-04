// pe10-8.cpp - uses the List class ADT
// This is exercise 8 of chapter 10 in C++ Primer Plus by Stephen Prata
// questionEight.cpp is accompanied by list.h and list.cpp

#include<iostream>
#include "list.h"

// prototypes for our functions (return void and take a reference)
inline void doubleValue(double & x) {x = 2*x;}
inline void square(double & x) {x = x*x;}
inline void halve(double & x) {x = x/2;}
inline void reciprocal(double & x) {x = 1/x;}

int main(void)
{
	// declare using directives
	using std::cout;
	using std::endl;
	using std::cin;

	// prompt user for values
	cout << "Using the List class, we can store up to \n"
	     << "as many entries as we want, but for this \n"
	     << "example, we limit it at 10" << endl;
	List l;

	// while (list not full || number not neg)
	// 	prompt and add values
	cout << "Enter a number (q to quit): ";
	double d;	
	while (cin >> d && l.isFull() == 0)
	{
		l.add(d);
		if (l.isFull() == 0)
			cout << "Enter a number (q to quit): ";
	}
	cin.clear();
	cin.ignore(256, '\n');
	cout << "You have entered " << l.numberOfItems()
	     << " items" << endl;

	// display items
	cout << "Here is your list: " << endl;;
	l.printList();
	 
	// while (q is not entered)
	// 	prompt user to choose a value from a menu of functions
	// 	display values of items
	cout << "Choose from the following (q to quit): "
	     << endl;
	cout << "1. doubleValue()          2. square()     \n"
	     << "3. halve()                4. reciprocal() \n";
	int choice;
	while (cin >> choice)
	{
		switch (choice)
		{
			case 1:
				l.visit(doubleValue);
				break;
			case 2:
				l.visit(square);
				break;
			case 3: 
				l.visit(halve);
				break;
			case 4:
				l.visit(reciprocal);
				break;
			default:
				cout << "Not an option" << endl;
				break;
		}
		cout << "Here is your new list: " << endl;
		l.printList();
		cout << "Choose from the following (q to quit): "
	     	     << endl;
		cout << "1. doubleValue()          2. square()     \n"
		     << "3. halve()                4. reciprocal() \n";
	}

	cout << "Bye!" << endl;
	return 0;
}















