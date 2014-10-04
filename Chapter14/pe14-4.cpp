// pe14-4.cpp -- tests BadDude class
// This is exercise 4 of chapter 14 in C++ Primer Plus 5e by Stephen Prata
// compile with person.cpp

#include<iostream>
#include<cstring> // for strchr()
#include<ctime>
#include<cstdlib>
#include"person.h"
const int SIZE = 4;

int main(void)
{
	using std::strchr;
	using std::cout;
	using std::cin;
	using std::endl;
	using std::strchr;

	srand(time(NULL));
	Person * pp[SIZE];

	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the person category:\n"
				<< "p: person  g: gunslinger  "
            << "k: poker player  b: bad dude \n"
				<< "q: quit\n";
		cin >> choice;
		while (strchr("pgkbq", choice) == NULL)
		{
			cout << "Please enter a p, g, k, b, or q: ";
			cin >> choice;
		}
		cin.get();	// get newline character
		if (choice == 'q')
			break;
		switch(choice)
		{
			case 'p':   pp[ct] = new Person;
							break;
			case 'g':   pp[ct] = new Gunslinger;
							break;
			case 'k':   pp[ct] = new PokerPlayer;
							break;
			case 'b': 	pp[ct] = new BadDude;
							break;
		}
		pp[ct]->Set();
		pp[ct]->Show();
		cout << "ct = " << ct << endl;
	}
	
	cout << "Your selection:" << endl << endl;
	for (int i = 0; i < ct; i++)
	{
		pp[i]->Show();
		cout << endl;
		delete *(pp + i);
	}
	return 0;
}
