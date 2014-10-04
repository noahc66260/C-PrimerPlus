// questionSeven.cpp -- uses the Complex class
// This is exercise 7 of chapter 11 in C++ Primer Plus by Stephen Prata
// this code is supplemented by complex0.cpp and questionSeven.cpp
// Note: this section of the code was given by the question to 
// test complex0.h and complex0.cpp

#include<iostream>
#include "complex0.h" 		// to avoid confusion with complex.h
int main()
{
	using namespace std;
	Complex a(3.0, 4.0); 	// initialize to (3,4i)
	Complex c;
	cout << "Enter a complex number (q to quit):\n";
	while (cin >> c)
	{
		cout << "c is " << c << '\n';
		cout << "complex conjugate is " << ~c << '\n';
		cout << "a is " << a << '\n';
		cout << "a + c is " << a + c << '\n';
		cout << "a - c is " << a - c << '\n';
		cout << "a * c is " << a * c << '\n';
		cout << "2 * c is " << 2 * c << '\n';
		cin.ignore(256, '\n');
		cout << "Enter a complex number (q to quit):\n";
	}
	cout << "Done!\n";
	return 0;
}
