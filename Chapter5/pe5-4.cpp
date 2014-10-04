// pe5-4.cpp -- the program asks the user for monthly sales of books and then sums the total number of books sold using arrays
// This is exercise 4 of chapter 5 in C++ Primer Plus by Stephen Prata

#include<iostream>

int main(void)
{
	using namespace std; 		
	const char * months[] = 
	{
		"January", 
		"February", 
		"March",
		"April", 
		"May", 
		"June", 
		"July", 
		"August", 
		"September", 
		"October", 
		"November", 
		"December"
	};
	int sales[12];
	int sum = 0;

	for (int i = 0; i < 12; i++)
	{
		cout << "Enter books sales for the month of " << months[i] << ": ";
		cin >> sales[i];
		sum += sales[i];
	}
	
	cout << "The total sales for the year is " << sum << endl;
	return 0;
}


