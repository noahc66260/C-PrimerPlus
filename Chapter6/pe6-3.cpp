// pe6-3.cpp -- displays a menu and reprompts the user if incorrect input is given
// This is exercise 3 of chapter 6 in C++ Primer Plus by Stephen Prata

#include<iostream>

int main(void)
{
	using namespace std; 
	
	// display menu
	cout << "Please enter one of the following choices: " << endl
	     << "c) carnivore \t\t p) pianist" << endl
	     << "t) tree      \t\t g) game" << endl;

	char ch;
	cin >> ch;


	// ensure that input is appropriate
	while (ch != 'c' && ch != 'p' && ch != 't' && ch != 'g' )
	{
		cout << "Please enter a c, p, t, or g: ";
		cin.ignore(100,'\n');
		cin >> ch;
	}

	// select an option from the menu
	switch (ch)
	{
		case 'c': 
			cout << "A wolf is a carnivore." << endl;
			break;
		case 'p':
			cout << "Wolfgang Amadeus Mozart was a pianist." << endl;
			break;
		case 't':
			cout << "A maple is a tree." << endl;
			break;
		case 'g': 
			cout << "Monopoly is a game." << endl;
			break;
	}

	return 0;
}
