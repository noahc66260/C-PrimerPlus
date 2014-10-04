// cd.cpp -- implementation of the Cd class
// This is exercise 1 of chapter 12 in C++ Primer Plus by Stephen Prata

#include<iostream> // for cout, endl
#include<cstring> // for strncpy
#include "cd.h"

Cd::Cd(const char * s1, const char * s2, int n, double x)
{
	using std::cout;
	using std::endl;
	
	strncpy(performers, s1, len_performer - 1);
	performers[len_performer - 1] = '\0';
	strncpy(label, s2, len_label - 1);
	label[len_label - 1] = '\0';

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
	strncpy(performers, d.performers, len_performer);
	strncpy(label, d.label, len_label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	performers[0] = '\0';
	label[0] = '\0';
	selections = 0;
	playtime = 0;
}

Cd::~Cd()
{
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
	strncpy(performers, d.performers, len_performer);
	strncpy(label, d.label, len_label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

