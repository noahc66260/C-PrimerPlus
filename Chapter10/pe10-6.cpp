// pe10-6.cpp - uses the Move class
// This is exercise 6 of chapter 10 in C++ Primer Plus by Stephen Prata
// questionSix.cpp is accompanied by move.h and move.cpp

#include<iostream>
#include "move.h"

int main(void)
{
	using std::cout;
	using std::endl;

	// initialize Move object
	cout << "Here is the default Move object" << endl;
	Move m;
	m.showmove();

	// initialize second Move object
	cout << "Here is a second object with coordinates ";
	cout << "(5, -3.2)" << endl;
	Move n(5, -3.2);
	n.showmove();

	cout << "Let's reset the values of the first object to ";
	cout << "coordinates (10, 10)" << endl;
	m.reset(10,10);
	m.showmove();

	// Let's add the two objects and assign its values to the
	// first object
	cout << "Let's add the coordinates of the two objects ";
	cout << "together " << endl;
	m = m.add(n);
	m.showmove();

	cout << "Bye!" << endl;

	return 0;
}
