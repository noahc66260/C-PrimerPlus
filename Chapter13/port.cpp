// port.cpp -- the Port class implementation
// This is exercise 4 of chapter 12 in C++ Primer Plus by Stephen Prata

#include<iostream>
#include<cstring>
#include "port.h"
using std::ostream;


Port::Port(const char * br, const char * st, int b)
{
	using std::cout;
	using std::endl;

	brand = new char[strlen(br) + 1];
	strcpy(brand, br);
	brand[strlen(br)] = '\0';

	strncpy(style, st, 19);
	style[20] = '\0';

	if (b < 0)
	{
		cout << "Number of bottles must be a positive integer." << endl;
		cout << "Setting bottles to 0." << endl;
		bottles = 0;
	}
	else
		bottles = b;
}

Port::Port(const Port & p) 	// copy constructor
{
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
}

Port & Port::operator=(const Port & p)
{
	if (this == &p)
		return *this;
	else
	{
		delete [] brand;
		brand = new char[strlen(p.brand) + 1];
		strcpy(brand, p.brand);
		strcpy(style, p.style);
		bottles = p.bottles;
	}
	return *this;
}

Port & Port::operator+=(int b) 	// adds b to bottles
{
	bottles += b;
	return *this;
}

Port & Port::operator-=(int b) 	// subtracts b from bottles, if available
{
	using std::cout;
	using std::endl;

	if (b > bottles)
	{
		cout << "You cannot subtract more bottles than you have!" << endl;
		cout << "Subtracting " << bottles << " bottles." << endl;
		bottles = 0;
	}
	else
		bottles -= b;

	return *this;
}

void Port::Show() const
{
	using std::cout;
	using std::endl;

	cout << "Brand: " << brand << endl;
	cout << "Kind: " << style << endl;
	cout << "Bottles: " << bottles << endl;
}

ostream & operator<<(ostream & os, const Port & p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}

