// Person.cpp - implementation of the Person class
// This is exercise 2 of chapter 10 in C++ Primer Plus by Stephen Prata
// This file is accompanied by Person.h and questionTwo.cpp

#include<iostream>
#include<cstring>
#include "Person.h"

// Constructor
Person::Person(const std::string & ln, const char * fn)
{
	using std::strncpy;

	lname = ln;
	strncpy(fname, fn, LIMIT);
	fname[LIMIT-1] = '\0';
}

// firstname, lastname format
void Person::Show() const 	
{
	using std::cout;
	using std::endl;
	
	cout << fname << ", " << lname << endl;
}

// lastname, firstname format
void Person::FormalShow() const 
{
	using std::cout;
	using std::endl;	

	cout << lname << ", " << fname << endl;
}
