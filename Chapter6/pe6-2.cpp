// pe6-2.cpp -- this program asks the user for donation values which are stored in an array. When the user enters non-numeric input or enters the maximum amount of donations, the program calculates the average donation and the number of donations above average. 
// This is exercise 2 of chapter 6 in C++ Primer Plus by Stephen Prata

#include<iostream>
const int Max = 10;

int main(void)
{
	using namespace std; 

	double donation[Max];		// array to hold donation values
	int index = 0; 			// index for donation array
	double value, total = 0;

	cout << "Enter value of donation number " << index + 1 << ": ";
	cin >> value;
	
	// prompt for and store donation values
	while (cin.good() && index < Max)
	{
		donation[index] = value;
		total += value;
		if (Max > ++index)
		{
			cout << "Enter value of donation number " << index + 1 << ": ";
			cin >> value;
		}		
	}

	cout << "The average donation was $" << total/index << endl;
	
	// calculate the number of donations above average
	int above_average = 0;
	for (int i = 0; i < index; i++)
	{
		if (donation[i] > total/index)
		{
			above_average++;
		}
	}

	cout << "The number of donations above average was " << above_average << endl;
	
	return 0;
}
