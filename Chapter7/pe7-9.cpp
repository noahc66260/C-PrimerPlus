// pe7-9.cpp -- calculates arithmetic through a function that accepts two numbers and a pointer to a function
// This is exercise 9 of chapter 7 in C++ Primer Plus by Stephen Prata

#include<iostream>

const int FUNCTIONS = 3;

// function prototypes
double add(double x, double y);
double multiply(double x, double y);
double subtract(double x, double y);
void calculate(double x, double y, double (*pf[])(double a, double b), int length);

int main(void)
{
	using namespace std; 

	// declare and initialize an array of pointers to functions
	double (*pf[FUNCTIONS])(double, double) = {add, multiply, subtract};

	cout << "Enter two numbers (q to quit): ";
	double x, y;

	while (cin >> x >> y)
	{
		cout << "The sum, product, and difference are as follows: ";
		calculate(x, y, pf, FUNCTIONS);
		cout << "Enter another two numbers (q to quit): ";
	}
	
	return 0;
}

// adds two numbers
double add(double x, double y)
{
	return x + y;
}

// multiplies two numbers
double multiply(double x, double y)
{
	return x * y;
}

// subtracts two numbers
double subtract(double x, double y)
{
	return x - y;
}

// makes calculations between two numbers through several designated functions
void calculate(double x, double y, double (*pf[])(double a, double b), int length)
{
	using namespace std;
	for (int i = 0; i < length; i++)
	{
		cout << (*pf[i])(x, y) << "  ";
	}
	cout << endl;
	return;
}
