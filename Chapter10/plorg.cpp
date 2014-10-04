// plorg.cpp - implementation of the Plorg class
// This is exercise 7 of chapter 10 in C++ Primer Plus by Stephen Prata
// plorg.cpp is accompanied by plorg.h and questionSeven.cpp

#include<iostream>
#include<cstring>
#include "plorg.h"

Plorg::Plorg(const char * name)
{
	std::strncpy(this->name, name, MAX);
	(this->name)[MAX - 1] = '\0';
	CI = 50;
}


void Plorg::changeCI(int CI)
{
	this->CI = CI;
	return;
}


void Plorg::show(void) const // prints name and CI to standard output
{
	using std::cout;
	using std::endl;
	
	cout << "Name: " << name << endl;
	cout << "Contentment Index: " << CI << endl;
	return;
}
