// pe7-5.cpp -- calculates the factorial of a number using a recursive function
// This is exercise 5 of chapter 7 in C++ Primer Plus by Stephen Prata

#include<iostream>

unsigned long int factorial(unsigned int n);

int main(void)
{
	using namespace std; 	
	cout << "Enter a number: ";
	unsigned int number;
	// I've chosen to make number unsigned since our data should be positive. However, I am unsure if this is best since now I cannot error check by checking to see if number is negative. On my computer, the terminal displays "Segmentation fault" and ends the program.

	while (cin >> number)
	{
		cout << number << "! = " << factorial(number) << endl;
		cout << "Another number (q to quit): ";
	}
	
	return 0;
}

// a recursive function
unsigned long int factorial(unsigned int n)
{
	if (0 == n)
		return 1;
	else
		return n * factorial(n - 1);
}
