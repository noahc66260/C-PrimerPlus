// pe5-9.cpp -- asks the user for the number of characters to be displayed in a row and prints a pattern
// This is exercise 9 of chapter 5 in C++ Primer Plus by Stephen Prata

#include<iostream>

int main(void)
{
	using namespace std; 
	int rows;

	cout << "Enter the number of rows: ";
	cin >> rows;

	for (int i = 1; i <= rows; i++) 
	{
		for (int k = 1; k <= rows - i; k++)
		{
			cout << ".";
		}
		for (int k = rows - i; k < rows; k++)
		{
			cout << "*";
		}
		cout << endl;
	}	
	
	return 0;
}


