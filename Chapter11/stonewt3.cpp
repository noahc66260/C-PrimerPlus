// stonewt3.cpp -- modified version of stonewt.cpp
// This is exercise 6 of chapter 11 in C++ Primer Plus by Stephen Prata
// see stonewt3.cpp or listing 11.17 in C++ Primer Plus for the original

#include<iostream>
using std::cout;
#include "stonewt3.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs)
{
	stone = int (lbs) / Lbs_per_stn; 	// integer division
	pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt() 		// default constructor, wt = 0
{
	stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt() 		// destructor
{
}

// show weight in stones
void Stonewt::show_stn() const
{
	cout << stone << " stone, " << pds_left << " pounds\n";
}

// show weight in pounds
void Stonewt::show_lbs() const
{
	cout << pounds << " pounds\n";
}

bool operator==(const Stonewt & s1, const Stonewt & s2)
{
	if (s1.pounds == s2.pounds)
		return true;
	else 
		return false;
}

bool operator!=(const Stonewt & s1, const Stonewt & s2)	
{
	return !(s1 == s2);
}

bool operator>=(const Stonewt & s1, const Stonewt & s2)
{
	if (s1.pounds >= s2.pounds)
		return true;
	else 
		return false;
}

bool operator>(const Stonewt & s1, const Stonewt & s2)
{
	if (s1.pounds > s2.pounds)
		return true;
	else 
		return false;
}

bool operator<=(const Stonewt & s1, const Stonewt & s2)
{
	if (s1.pounds <= s2.pounds)
		return true;
	else 
		return false;
}

bool operator<(const Stonewt & s1, const Stonewt & s2)
{
	if (s1.pounds < s2.pounds)
		return true;
	else 
		return false;
}

std::ostream & operator<<(std::ostream & os, 
		const Stonewt & s)
{
	os << s.pounds;
	return os;
}

