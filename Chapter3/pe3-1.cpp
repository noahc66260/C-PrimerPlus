// pe3-1.cpp -- Converts height of user from inches to feet and inches.
// This is exercise 1 of chapter 3 in C++ Primer Plus by Stephen Prata

#include<iostream>

int main(void)
{
	using namespace std;
	const int inches_per_foot = 12;
	cout << "Enter your height in inches: ";
	int height_inches;
	cin >> height_inches;
	cout << "You are " << height_inches / inches_per_foot << " feet "; 
	cout << "and " << height_inches % inches_per_foot << " inches tall." << endl;
	return 0;
}
