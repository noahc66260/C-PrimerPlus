// pe9-1.cpp -- uses the golf header file
// This is exercise 1 of chapter 9 in C++ Primer Plus by Stephen Prata
// pe9-1.cpp is accompanied by golf.h and golf.cpp

#include<iostream>
#include "golf.h"

const int size = 5;

int main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;

	// players are entered and cataloged
	cout << "You may enter up to " << size << " players." << endl;
	int players = 0;
	golf list[size];
	while (players < size && setgolf(list[players]))
	{
		players++;
	}

	// players are displayed
	cout << "Here are your players: " << endl;
	if (players > 0)
	{
		for (int i = 0; i < players; i++)
		{
			showgolf(list[i]);
		}

		// user enters new handicap value
		cout << "Enter a number, please: ";
		int newHandicap;
		cin.clear();

		while(!(cin >> newHandicap))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Try again: ";
		}

		// all players have handicap value reset to that given by
		// the user and players are redisplayed
		cout << "Here are your players with their new handicaps: "
		     << endl;
		for (int i = 0; i < players; i++)
		{
			handicap(list[i], newHandicap);
			showgolf(list[i]);
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
		cout << "Enter the player name: ";
		
		cin.get(lastPlayerName, Len);
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
		
		golf lastPlayer;
		setgolf(lastPlayer, lastPlayerName, lastPlayerHandicap);
		cout << "Here's what you entered: " << endl;
		showgolf(lastPlayer);
	}

	return 0;
}











