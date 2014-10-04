// winec.cpp -- implementation of the wine class
// This is exercise 1 of chapter 14 in C++ Primer Plus 5e by Stephen Prata

#include"winec.h"
#include<iostream>
using std::string;

Wine::Wine(const char * l, int y, const int yr[], const int bot[])
{
	label = l;
	years = y;
	data.first.resize(years);
	data.second.resize(years);
	for (int i = 0; i < years; i++)
	{
		data.first[i] = yr[i];
		data.second[i] = bot[i];
	}
}

Wine::Wine(const char * l, int y)
{
	label = l;
	years = y;
	data.first.resize(years);
	data.second.resize(years);
}

Wine::~Wine()
{
}

void Wine::Show() const
{
	using std::cout;
	using std::endl;

	cout << "Wine: " << label << endl;
	cout << "\tYear\tBottles" << endl;
	for (int i = 0; i < years; i++)
	{
		cout << "\t" << data.first[i] << "\t";
		cout << data.second[i] << endl;
	}
}

void Wine::GetBottles()
{
	using std::cout;
	using std::endl;
	using std::cin;

	cout << "Enter " << label << " data for " << years << " year(s):\n";
	int input;
	for (int i = 0; i < years; i++)
	{
		cout << "Enter year: ";
		cin >> input;
		data.first[i] = input;
		cout << "Enter bottles for that year: ";
		cin >> input;
		data.second[i] = input;
	}
}

const string & Wine::Label() const
{
	return label;
}

int Wine::sum() const
{
	int sum = 0;
	for (int i = 0; i < years; i++)
		sum += data.second[i];
	return sum;
}
















