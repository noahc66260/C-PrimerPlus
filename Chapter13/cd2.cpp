// cd2.cpp -- implementation of the Cd class with dynamic memory
// This is exercise 2 of chapter 12 in C++ Primer Plus by Stephen Prata

#include<iostream> // for cout, endl
#include<cstring>
#include "cd2.h"

Cd::Cd(const char * s1, const char * s2, int n, double x)
{
	using std::cout;
	using std::endl;

	if (NULL == s1)
	{
		performers = NULL;
	}
	else
	{
		performers = new char[strlen(s1) + 1];
		strcpy(performers, s1);
	}

	if (NULL == s2)
	{
		label = NULL;
	}
	else
	{
		label = new char[strlen(s2) + 1];
		strcpy(label, s2);
	}


	if (n < 0)
	{
		cout << "Selections must be a positive integer. ";
		cout << "Setting selections to 0." << endl;
		selections = 0;
	}
	else
		selections = n;

	if (x < 0)
	{
		cout << "Play time must be a positive real number. ";
		cout << "Setting play time to 0." << endl;
		playtime = 0;
	}
	else
		playtime = x;
}

Cd::Cd(const Cd & d)
{	
	if (NULL == d.performers)
	{
		performers = NULL;
	}
	else
	{
		int len1 = strlen(d.performers);
		performers = new char[len1 + 1];
		strcpy(performers, d.performers);
	}

	if (NULL == d.label)
	{
		label = NULL;
	}
	else
	{
		int len2 = strlen(d.label);
		label = new char[len2 + 1];
		strcpy(label, d.label);
	}

	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	performers = NULL;
	label = NULL;
	selections = 0;
	playtime = 0;
}

Cd::~Cd()
{
	delete [] performers;
	delete [] label;
}

void Cd::Report() const
{
	using std::cout;
	using std::endl;

	cout << "Performers: " << performers << endl;
	cout << "label: " << label << endl;
	cout << "Selections: " << selections << endl;
	cout << "Play time: " << playtime << endl;
}

Cd & Cd::operator=(const Cd & d)
{
	if (this == &d)
		return *this;
	else
	{
		delete [] performers;
		delete [] label;
	
		if (NULL == d.performers)
		{
			performers = NULL;
		}
		else
		{
			int len1 = strlen(d.performers);
			performers = new char[len1 + 1];
			strcpy(performers, d.performers);
		}

		if (NULL == d.label)
		{
			label = NULL;
		}
		else
		{
			int len2 = strlen(d.label);
			label = new char[len2 + 1];
			strcpy(label, d.label);
		}		
	}
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

