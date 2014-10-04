// stonewt2.cpp -- modified version of stonewt.cpp
// This is exercise 5 of chapter 11 in C++ Primer Plus by Stephen Prata
// see stonewt2.cpp or listing 11.17 in C++ Primer Plus for the original

#include<iostream>
using std::cout;
#include "stonewt2.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs, char st)
{
	stone = int (lbs) / Lbs_per_stn; 	// integer division
	pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;

	if ('1' == st || '2' == st || '3' == st)
		state = st;
	else
	{
		cout << "State must be '1', '2', or '3'. ";
		cout << "Setting state to '1'\n";
		state = '1';
	}
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs, char st)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;

	if ('1' == st || '2' == st || '3' == st)
		state = st;
	else
	{
		cout << "State must be '1', '2', or '3'. ";
		cout << "Setting state to '1'\n";
		state = '1';
	}
}

Stonewt::Stonewt() 		// default constructor, wt = 0
{
	stone = pounds = pds_left = 0;
	state = '1';
}

Stonewt::~Stonewt() 		// destructor
{
}

void Stonewt::set_state(char st)
{
	if ('1' == st || '2' == st || '3' == st)
		state = st;
	else
	{
		cout << "State must be '1', '2', or '3'. ";
		cout << "Setting state to '1'\n";
		state = '1';
	}
}

Stonewt operator+(const Stonewt & s1, const Stonewt & s2)
{
	double tot_pounds = s1.pounds + s2.pounds;
	return Stonewt(tot_pounds);
}

Stonewt operator-(const Stonewt & s1, const Stonewt & s2)
{
	double tot_pounds = s1.pounds - s2.pounds;
	return Stonewt(tot_pounds);
}

Stonewt operator*(const Stonewt & s, double d)
{
	double tot_pounds = s.pounds * d;
	return Stonewt(tot_pounds);
}

Stonewt operator*(double d, const Stonewt & s)
{
	return s * d;
}

std::ostream & operator<<(std::ostream & os, const Stonewt & s)
{
	if ('1' == s.state)
		os << s.stone << " stone, " << s.pds_left << " pounds";
	else if ('2' == s.state)
		os << int (s.pounds) << " pounds";
	else if ('3' == s.state)
		os << s.pounds << " pounds";
	
	return os;
}
