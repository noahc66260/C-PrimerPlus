// pe8-2.cpp -- records information about candy bars in a structure and displays data
// This is exercise 2 of chapter 8 in C++ Primer Plus by Stephen Prata

#include<iostream>
#include<cstring>

const int MAX = 3;	// max number of candy bars to enter
const int LENGTH = 40;	// max length of name of candy bar

struct CandyBar
{
	char name[LENGTH];
	float weight;
	int calories;
};

// function to initialize variable of type CandyBar
void setCandyBar( CandyBar & candy, const char * str = "Millennium Munch", double weight = 2.85, int calories = 350);

// function to display values in CandyBar
void displayCandyBar( const CandyBar & candy);

int main(void)
{
	using namespace std;

	cout << "Enter information of up to " << MAX << " candy bars." << endl;
	CandyBar candy[MAX];
	
	int i = 0;	
	cout << "Enter the name of candy bar " << i + 1 << " (q to quit): ";
	char name[LENGTH];
	cin.get(name, LENGTH);

	// empty buffer for large input
	if (strlen(name) == LENGTH - 1)
		cin.ignore(100, '\n');

	float weight; 
	int calories;

	// exit condition is if MAX bars are already entered or user enters 'q' for the name
	while (i < MAX && (1 != strlen(name) || name[0] != 'q'))
	{
		cout << "Enter the weight: ";
		
		// ensure appropriate input 
		while ((cin >> weight) == 0)
		{
			cin.clear();
			cin.ignore(100,'\n');
			cout << "Bad input, please enter the weight again: ";
		}
		cout << "Enter the calories: ";

		// ensure appropriate input 
		while ((cin >> calories) == 0)
		{
			cin.clear();
			cin.ignore(100,'\n');
			cout << "Bad input, please enter the calories as an integer: ";
		}

		cin.get(); 	// discard newline character in buffer
		setCandyBar( candy[i], name, weight, calories);
		i++;
		
		// Only prompt for more input if it is within appropriate limits
		if (i < MAX)
		{
			cout << "Enter the name of candy bar " << i + 1 << " (q to quit): ";
			cin.get(name, 40);

			// discard extra input if over 39 characters
			if (strlen(name) == 39)
				cin.ignore(100, '\n');
		}
	}

	// display the candy bars given by the user
	for(int j = 0; j < i; j++)
	{
		cout << "Candy bar number " << j + 1 << ":" << endl;
		displayCandyBar(candy[j]);
	}
	
	cout << "Let's see what an uninitialzed candy bar looks like." << endl;
	CandyBar tasty;
	setCandyBar(tasty);
	displayCandyBar(tasty);
	
	return 0;
}

void setCandyBar( CandyBar & candy, const char * str, double weight, int calories)
{
	strcpy(candy.name, str);
	candy.weight = weight;
	candy.calories = calories;
	return;
}

void displayCandyBar( const CandyBar & candy)
{
	using namespace std;
	cout << "Name: " << candy.name << endl;
	cout << "Weight: " << candy.weight << endl;
	cout << "Calories: " << candy.calories << endl;
	return;
}


