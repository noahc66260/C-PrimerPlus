// pe6-4.cpp -- reports member data according to what the user selects from the menu data
// This is exercise 4 of chapter 6 in C++ Primer Plus by Stephen Prata

#include<iostream>
// Benevolent Order of Programmers name structure
const int strsize = 20;
const int ListLength = 5;
struct bop
{
	char fullname[strsize]; // real name
	char title[strsize]; 	// job title
	char bopname[strsize]; 	// secret BOP name
	int preference; 	// 0 = fullname, 1 = title, 2 = bopname
};

int main(void)
{
	using namespace std; 
	
	// create array of 5 strucures
	bop list[ListLength] = 
	{
		{"Barak Obama", "President", "Obamarama", 1},
		{"Elvis", "Singer", "The man, the legend", 0},
		{"Aristotle", "Philosopher", "The Thinker", 2},
		{"Einstein", "Physicist", "Genius", 1}, 
		{"Marlon Brando", "Actor", "Bad boy", 0}
	};

	// display menu
	cout << "Benevolent Order of Programmers Report" << endl
	     << "a. display by name    \t\t b. display by title" << endl
	     << "c. display by bopname \t\t d. display by preference" << endl
	     << "q. quit" << endl
	     << "Enter your choice: ";

	// retrieve input, proceed if input is not 'q'
	char ch;
	cin >> ch;
	while (ch != 'q')
	{
		// reprompt user if input is not in range
		while (ch != 'a' && ch != 'b' && ch != 'c' && ch != 'd')
		{
			cin.ignore(100, '\n');			// discard input
			cout << "Enter a, b, c, d, or q: ";
			cin >> ch;
			if (ch == 'q')				// quit program if input is 'q'
			{
				goto end_of_program;
			}
		}

		// begin switch case since input is appropriate
		switch (ch)
		{
			case 'a':	// list names
				for (int i = 0; i < ListLength; i++)
				{
					cout << list[i].fullname << endl; 
				}
				break;
			case 'b':	// list titles
				for (int i = 0; i < ListLength; i++)
				{
					cout << list[i].title << endl;
				}
				break;
			case 'c': 	// list bopnames
				for (int i = 0; i < ListLength; i++)
				{
					cout << list[i].bopname << endl;
				}
				break;
			case 'd': 	// list preferences
				for (int i = 0; i < ListLength; i++)
				{
					switch (list[i].preference)
					{
						case 0: 
							cout << list[i].fullname << endl;
							break;
						case 1: 
							cout << list[i].title << endl;
							break;
						case 2: 
							cout << list[i].bopname << endl;
					}
				}
				break;
		}
		
		cout << "Next choice: ";		// reprompt user to make new selection
		cin >> ch;
	}

	end_of_program:
	cout << "Bye!" << endl;
		
	return 0;
}
