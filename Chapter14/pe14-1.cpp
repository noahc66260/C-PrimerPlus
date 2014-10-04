// pe14-1.cpp -- using Wine class with containment
// This is exercise 1 of chapter 14 in C++ Primer Plus 5e by Stephen Prata
// Note: The following code was given by the book to test the Wine class
// compile with winec.cpp

#include<iostream>
#include"winec.h"

int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "Enter name of wine: ";
	char lab[50];
	cin.getline(lab, 50);
	cout << "Enter number of years: ";
	int yrs;
	cin >> yrs;

	Wine holding(lab, yrs); // store label, years, give arrays yrs elements
	holding.GetBottles(); 	// solicit input for year, bottle count
	holding.Show(); 		// display object contents

	const int YRS = 3;
	int y[YRS] = {1993, 1995, 1998};
	int b[YRS] = { 48, 60, 72};
	// create new object, initialize using data in arrays y and b
	Wine more("Gushing Grape Red", YRS, y, b);
	more.Show();
	cout << "Total bottles for " << more.Label() // use Label() method
		<< ": " << more.sum() << endl;
	cout << "Bye\n";
	return 0;
}
