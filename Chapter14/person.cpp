// person.cpp -- Implementation for the Person class and derived classes
// This is exercise 4 of chapter 14 in C++ Primer Plus 5e by Stephen Prata

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string> // for getline function.
#include"person.h"
using std::string;

// Person methods

void Person::Data() const
{
	using std::cout;
	using std::endl;

	cout << "First Name: " << firstname << endl;
	cout << "Last Name: " << lastname << endl;
}


Person::Person(const string & first, const string & last) : firstname(first), lastname(last) {}

void Person::Show() const
{
	using std::cout;
	using std::endl;

	cout << "Type Person" << endl;	
	Data();
}

void Person::Set()
{
	using std::cout;
	using std::string;
	using std::cin;
	using std::endl;

	cout << "Enter the first name: ";
	getline(cin, firstname);
	cout << "Enter the last name: ";
	getline(cin, lastname);
}


// Gunslinger Methods
Gunslinger::Gunslinger(string first, string last, double d, 
		int n) : Person(first, last), drawtime(d), notches(n) {}

void Gunslinger::Data() const
{
	using std::cout;
	using std::endl;
	cout << "Draw time: " << drawtime << endl;
	cout << "Notches: " << notches << endl;
}

void Gunslinger::setData()
{
	using std::cout;
	using std::cin;
	using std::endl;

	cout << "Enter the draw time: ";
	cin >> drawtime;
	while (!cin || drawtime < 0)
	{
		cin.clear();
		cout << "Draw time must be a positive number.\nTry again: ";
		cin >> drawtime;
	}

	cout << "Enter the number of notches: ";
	cin >> notches;
	while (!cin || notches < 0)
	{
		cin.clear();
		cout << "Draw time must be a positive integer.\nTry again: ";
		cin >> notches;
	}
}

void Gunslinger::setDrawTime(double d)
{
	if (d < 0)
	{
		std::cerr << "Error, draw time cannot be negative. ";
		std::cerr << "Setting draw time to 0." << std::endl;
		drawtime = 0;
	}
	else
		drawtime = d;
}

void Gunslinger::setNotches(int n)
{
	if (n < 0)
	{
		std::cerr << "Error, notches cannot be negative. ";
		std::cerr << "Setting notches to 0." << std::endl;
		notches = 0;
	}
	else
		notches = n;
}

void Gunslinger::Show() const
{
	std::cout << "Type Gunslinger" << std::endl;
	Person::Data();
	Data();
}


// PokerPlayer Methods
PokerPlayer::PokerPlayer(string first, string last) : Person(first, last) {}

void PokerPlayer::Show() const 
{
	std::cout << "Type Poker Player" << std::endl;
	Person::Data();
}

// BadDude Methods
BadDude::BadDude(string first, string last, double d, 
		int n) : Person(first, last), Gunslinger(first, last, d, n), 
		PokerPlayer(first, last) {}

void BadDude::Show() const
{
	std::cout << "Type BadDude" << std::endl;
	Person::Data();
	Gunslinger::Data();
	PokerPlayer::Data();
}

void BadDude::Set()
{
	Person::Set();
	Gunslinger::setData();
}
