// pe4-5.cpp -- we create a structure whose parameters are the brand, weight, and calories of a candy bar; initialize it; and display its contents
// This is exercise 5 of chapter 4 in C++ Primer Plus by Stephen Prata

#include<iostream>

int main(void)
{
	using namespace std;
	struct CandyBar
	{
		char brand[20];
		float weight;
		int calories;
	} snack = 
	{
		"Mocha Munch",
		2.3,	
		350
	};
	
	cout << "Our snack brand is " << snack.brand << endl;
	cout << "The weight is " << snack.weight << endl;
	cout << "And it contains " << snack.calories << " calories" << endl;

	return 0;
}


