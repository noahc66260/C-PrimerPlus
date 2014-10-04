// pe3-5.cpp -- computes miles per gallons driven by a vehicle
// This is exercise 5 of chapter 3 in C++ Primer Plus by Stephen Prata

#include<iostream>

int main(void)
{
	using namespace std;
	cout << "How many miles have you driven? ";
	double miles;
	cin >> miles;
	cout << "How many gallons have you used? ";
	double gallons;
	cin >> gallons;
	cout << "Your car has gotten " << miles/gallons << " miles per gallon" << endl;
}
