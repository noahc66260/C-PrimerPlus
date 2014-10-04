// pe11-5.cpp -- uses the Stonewt class
// This is exercise 5 of chapter 11 in C++ Primer Plus by Stephen Prata
// compile with the stonewt2.cpp

#include<iostream>
#include "stonewt2.h"

int main(void)
{
	using namespace std;
	
	Stonewt jimmy(150.0);
	Stonewt bobby(200.0, '2');
	Stonewt danny(125.0, '3');

	cout << "Jimmy's weight: " << jimmy << endl;
	cout << "Bobby's weight: " << bobby << endl;
	cout << "Danny's weight: " << danny << endl;

	cout << "Jimmy + Bobby's weight: " << jimmy + bobby << endl;
	cout << "Bobby - Danny's weight: " << bobby - danny << endl;
	cout << "10 * Danny's weight: " << 10 * danny << endl;

	return 0;
}
