// pe10-2.cpp - uses the Person class
// This is exercise 2 of chapter 10 in C++ Primer Plus by Stephen Prata
// This file is accompanied by Person.h and Person.cpp

#include<iostream>
#include "Person.h"

int main()
{
	using std::cout;
	using std::endl;

	Person one;
	Person two("Smythecraft");
	Person three("Dimwiddy", "Sam");
	one.Show();
	cout << endl;
	one.FormalShow();
	cout << endl;
	two.Show();
	cout << endl;
	two.FormalShow();
	cout << endl;
	three.Show();
	cout << endl;
	three.FormalShow();
	cout << endl;
	
	return 0;
}
