// winec2.cpp -- implementation of the wine class
// This is exercise 1 of chapter 14 in C++ Primer Plus 5e by Stephen Prata

#include"winec2.h"
#include<iostream>
using std::string;

Wine::Wine(const char * l, int y, const int yr[], const int bot[]) :
	PairArray(ArrayInt(y), ArrayInt(y)), string(l)
{
	years = y;
	for (int i = 0; i < years; i++)
	{
		PairArray::first()[i] = yr[i];
		PairArray::second()[i] = bot[i];
	}
}

Wine::Wine(const char * l, int y) : 
	PairArray(ArrayInt(y), ArrayInt(y)), string(l)
{
	years = y;
}

Wine::~Wine()
{
}

void Wine::Show() const
{
	using std::cout;
	using std::endl;

	cout << "Wine: " << Label() << endl;
	cout << "\tYear\tBottles" << endl;
	for (int i = 0; i < years; i++)
	{
		cout << "\t" << PairArray::first()[i] << "\t";
		cout << PairArray::second()[i] << endl;
	}
}

void Wine::GetBottles()
{
	using std::cout;
	using std::endl;
	using std::cin;

	cout << "Enter " << Label() << " data for " << years << " year(s):\n";
	int input;
	for (int i = 0; i < years; i++)
	{
		cout << "Enter year: ";
		cin >> input;
		PairArray::first()[i] = input;
		cout << "Enter bottles for that year: ";
		cin >> input;
		PairArray::second()[i] = input;
	}
}

const string & Wine::Label() const
{
	return (const string &) (*this);
}

int Wine::sum() const
{
	int sum = 0;
	for (int i = 0; i < years; i++)
		sum += PairArray::second()[i];
	return sum;
}
















