// classic.cpp -- implementation of the Classic class
// This is exercise 1 of chapter 12 in C++ Primer Plus by Stephen Prata

#include "classic.h"
#include <iostream>
#include <cstring>

Classic::Classic() : Cd()
{
	primary_work[0] = '\0';
}

Classic::Classic(const char * primary, Cd & d) : Cd(d)
{
	strncpy(primary_work, primary, len_primary-1);
	primary_work[len_primary-1] = '\0';
}

Classic::Classic(const char * primary, const char * s1, 
	const char * s2, int n, double x) : Cd(s1, s2, n, x)
{
	strncpy(primary_work, primary, len_primary-1);
	primary_work[len_primary-1] = '\0';
}

Classic::Classic(const Classic & c) : Cd(c)
{
	strncpy(primary_work, c.primary_work, len_primary-1);
	primary_work[len_primary-1] = '\0';	
}

Classic::~Classic()
{
}

void Classic::Report() const
{
	using std::cout;
	using std::endl;

	Cd::Report();
	cout << "Primary Work: " << primary_work << endl;
}

Classic & Classic::operator=(const Classic & c)
{
	Cd::operator=(c);
	strncpy(primary_work, c.primary_work, len_primary-1);
	primary_work[len_primary-1] = '\0';		
	return *this;
}

