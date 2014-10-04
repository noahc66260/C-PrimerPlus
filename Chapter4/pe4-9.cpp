// pe4-9.cpp -- we create a dynamic array of a structure whose parameters are the brand, weight, and calories of a candy bar; initialize it; and display its contents
// This is exercise 9 of chapter 4 in C++ Primer Plus by Stephen Prata

#include<iostream>
#include<cstring>
struct CandyBar
	{
		char brand[20];
		float weight;
		int calories;
	};

int main(void)
{
	using namespace std;

	CandyBar * snacks = new CandyBar [3];
	
	strcpy(snacks->brand, "Twix");
	snacks->weight = 1.1;
	snacks->calories = 200;

	strcpy((snacks+1)->brand, "Snickers");
	(snacks+1)->weight = 2.5;
	(snacks+1)->calories = 300;

	strcpy((snacks+2)->brand, "Three Musketeers");
	(snacks+2)->weight = 2.1;
	(snacks+2)->calories = 150;
	
	cout << "For our first snack: " << endl;
	cout << "Our snack brand is " << snacks[0].brand << endl;
	cout << "The weight is " << snacks[0].weight << endl;
	cout << "And it contains " << snacks[0].calories << " calories" << endl << endl;

	cout << "For our second snack: " << endl;
	cout << "Our snack brand is " << snacks[1].brand << endl;
	cout << "The weight is " << snacks[1].weight << endl;
	cout << "And it contains " << snacks[1].calories << " calories" << endl << endl;

	cout << "For our third snack: " << endl;
	cout << "Our snack brand is " << snacks[2].brand << endl;
	cout << "The weight is " << snacks[2].weight << endl;
	cout << "And it contains " << snacks[2].calories << " calories" << endl;

	delete [] snacks;

	return 0;
}


