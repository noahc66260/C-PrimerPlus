// pe7-1.cpp -- calculates the harmonic mean of two numbers
// This is exercise 1 of chapter 7 in C++ Primer Plus by Stephen Prata

#include<iostream>

// function prototype
double harmonic(double x, double y);

int main(void)
{
	using namespace std; 	
	cout << "Enter two numbers (0 to exit): ";
	double x, y;
	
	while (cin >> x >> y && x != 0 && y != 0)
	{
		cout << "The harmonic mean of " << x << " and " << y 
		     << " is " << harmonic(x,y) << endl;
		cout << "Enter two numbers (0 to exit): ";
	}
	cout << "Bye!" << endl;	
	
	return 0;
}

// function definition
double harmonic(double x, double y)
{
	return 2.0 * x * y / (x + y);
}
