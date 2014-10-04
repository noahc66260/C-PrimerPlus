// classic2.cpp -- implementation of the Classic class with dynamic memory
// This is exercise 2 of chapter 12 in C++ Primer Plus by Stephen Prata

#include "classic2.h"
#include <iostream>
#include <cstring>

Classic::Classic() : Cd()
{
	primary_work = NULL;
}

Classic::Classic(const char * primary, Cd & d) : Cd(d)
{
	if (NULL == primary)
	{
		primary_work = NULL;
	}
	else
	{
		int len = strlen(primary);
		primary_work = new char[len + 1];
		strcpy(primary_work, primary);		
	}

}

Classic::Classic(const char * primary, const char * s1, 
	const char * s2, int n, double x) : Cd(s1, s2, n, x)
{
	if (NULL == primary)
	{
		primary_work = NULL;
	}
	else
	{
		int len = strlen(primary);
		primary_work = new char[len + 1];
		strcpy(primary_work, primary);		
	}
}

Classic::Classic(const Classic & c) : Cd(c)
{
	if (NULL == c.primary_work)
	{
		primary_work = NULL;
	}
	else
	{
		int len = strlen(c.primary_work);
		primary_work = new char[len + 1];
		strcpy(primary_work, c.primary_work);		
	}
}

Classic::~Classic()
{
	delete [] primary_work;
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
	if (this == &c)
		return *this;
	else
	{
		Cd::operator=(c);
		delete [] primary_work;
		if (NULL == c.primary_work)
		{
			primary_work = NULL;
		}
		else
		{
			int len = strlen(c.primary_work);
			primary_work = new char[len + 1];
			strcpy(primary_work, c.primary_work);		
		}
		return *this;
	}
}

