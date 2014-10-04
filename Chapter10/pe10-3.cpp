// pe10-3.cpp -- uses the golf class
// This is exercise 3 of chapter 9 in C++ Primer Plus by Stephen Prata
// questionThree.cpp is accompanied by golf2.h and golf2.cpp

#include<iostream>
#include "golf2.h"

const int size = 5;

int main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;

	// players are entered and cataloged
	cout << "You may enter up to " << size << " players." << endl;
	int players = 0;
	Golf list[size];
	while (players < size && list[players].setgolf())
	{
		players++;
		cin.ignore(100, '\n');
	}

	// players are displayed
	cout << "Here are your players: " << endl;
	if (players > 0)
	{
		for (int i = 0; i < players; i++)
			list[i].showgolf();

		// user enters new handicap value
		cout << "Enter a number, please: ";
		int newHandicap;
		//cin.clear(); 	I am unsure why this is here

		while(!(cin >> newHandicap))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Try again: ";
		}
	
		// discard extra input
		while (cin.get() != '\n')
			continue;

		// all players have handicap value reset to that given by
		// the user and players are redisplayed
		cout << "Here are your players with their new handicaps: "
		     << endl;
		for (int i = 0; i < players; i++)
		{
			list[i].setHandicap(newHandicap);
			list[i].showgolf();
		}
	}
	else
	{
		cout << "No players on file." << endl;
	}

	cout << "Before you go, would you like to make "
	     << "one more player (yes or no): ";
	char ch;
	cin.get(ch);
	while (cin.get() != '\n')
		continue;
	if (ch == 'y' || ch == 'Y')
	{
		char lastPlayerName[Len];
		int lastPlayerHandicap;
		cout << "Enter the player name ";
		cout << "(or enter nothing to quit): ";
		
		cin.get(lastPlayerName, Len);
		
		// exit if user enters nothing
		if (lastPlayerName[0] == '\0')
		{
			cin.clear();
			return 0;
		}

		while (cin.get() != '\n')
			continue;
	
		cout << "Enter the player handicap: ";
		while(!(cin >> lastPlayerHandicap))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Try again: ";
		}

		Golf p(lastPlayerName, lastPlayerHandicap);
		cout << "Here's what you entered: " << endl;
		p.showgolf();
	}

	return 0;
}











