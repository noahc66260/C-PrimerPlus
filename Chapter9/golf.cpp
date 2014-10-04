// golf.cpp -- function definitions for golf header file
// This is exercise 1 of chapter 9 in C++ Primer Plus by Stephen Prata
// golf.cpp is accompanied by golf.h and questionOne.cpp

#include "golf.h"
#include<cstring>
#include<iostream>

// non-interactive version:
// function sets golf structure to provided name, handicap
// using values passed as arguments to the function
void setgolf(golf & g, const char * name, int hc)
{
	std::strcpy(g.fullname, name);
	g.handicap = hc;
	return;
}

// interactive version:
// function solicits name and handicap from user
// and sets the members of g to the values entered
// returns 1 if name is entered, 0 if name is empty string
int setgolf(golf & g)
{
	using std::cout;
	using std::cin;
	using std::endl;	

	cout << "Enter the player's full name (enter nothing to quit): ";
	cin.get(g.fullname, Len);
	if ((g.fullname)[0] == '\0')
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
		cin >> g.handicap;
		cin.get(); 	// discard newline character from buffer
		return 1;
	}
}

// function resets handicap to new value
void handicap(golf & g, int hc)
{
	g.handicap = hc;
	return;
}

// function displays contents of golf structure
void showgolf(const golf & g)
{
	using std::cout;
	using std::endl;
	
	cout << "Player name: " << g.fullname << endl;
	cout << "Player handicap: " << g.handicap << endl;
	return;
}


















