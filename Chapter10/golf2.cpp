// golf2.cpp -- function definitions for Golf class
// This is exercise 3 of chapter 9 in C++ Primer Plus by Stephen Prata
// golf2.cpp is accompanied by golf2.h and questionThree.cpp

#include "golf2.h"
#include<cstring>
#include<iostream>

Golf::Golf()
{
}

// non-interactive version:
// function sets golf structure to provided name, handicap
// using values passed as arguments to the function
Golf::Golf(const char * fullname, int handicap)
{
	if ('\0' == fullname[0])
		return;
	else
	{
		std::strcpy(this->fullname, fullname);
		this->handicap = handicap;
		return;
	}
}

// interactive version:
// function solicits name and handicap from user
// and sets the members of g to the values entered
// returns 1 if name is entered, 0 if name is empty string
int Golf::setgolf()
{
	// prompts user for values and calls a constructor
	// to create a temporary object which is assigned
	// to the object that called the function.

	using std::cout;
	using std::cin;	

	cout << "Enter the player's full name (enter nothing to quit): ";

	// store values in local variables
	char fullname[Len];
	int handicap;

	cin.get(fullname, Len);
	if ((fullname)[0] == '\0')
	{
		cin.clear();  	// clear error flags
		cin.get();	// discard newline character 
		return 0;
	}
	else
	{
		while (cin.get() != '\n')
			continue;
		cout << "Enter the player's handicap: ";

		while(!(cin >> handicap))
		{
			cin.clear();
			while(cin.get() != '\n')
				continue;
			cout << "Try again: ";
		}
		cin.get(); 	// discard newline character from buffer

		// create temporary object and assign it
		// to invoking object
		Golf player(fullname, handicap);
		*this = player;

		return 1;
	}
}

// function resets handicap to new value
void Golf::setHandicap(int handicap)
{
	this->handicap = handicap;
	return;
}

// function displays contents of golf structure
void Golf::showgolf() const
{
	using std::cout;
	using std::endl;
	
	cout << "Player name: " << this->fullname << endl;
	cout << "Player handicap: " << (this->handicap) << endl;
	return;
}


















