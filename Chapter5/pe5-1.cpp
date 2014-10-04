// pe5-1.cpp -- asks the user for two numbers and sums all the integers between them, inclusive. The program assumes that the first integer the user enters is smaller than the second
// This is exercise 1 of chapter 5 in C++ Primer Plus by Stephen Prata

#include<iostream>

int main(void)
{
	using namespace std; 
	cout << "Enter a number: ";
	int first;
	cin >> first;
	cout << "Enter another number larger than the first: ";
	int second;
	cin >> second;
	
	if (second < first)
	{
		cout << "Error. Program Abort" << endl;
		return 1;
	}

	int sum = 0;
	int temp = first;
	while (temp <= second)
	{
		sum += temp;
		temp += 1;
	}

	cout << "The sum of all integers " << first << " through " << second
	     << " is " << sum << endl;
	return 0;
}

