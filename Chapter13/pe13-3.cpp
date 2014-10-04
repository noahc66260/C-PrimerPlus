// pe13-3.cpp -- uses baseDMA, lacksDMA, and hasDMA objects
// This is exercise 3 of chapter 12 in C++ Primer Plus by Stephen Prata
// compile with dma2.cpp

#include<iostream>
#include "dma2.h"

const int ArrLength = 3;
const int LEN = 40;

int main(void)
{
	using namespace std;

	abcDMA * arr[ArrLength];

	char label[LEN];
	char style[LEN];
	char color[LEN];
	int rating;
	int choice;
	for (int i = 0; i < ArrLength; i++)
	{
		cout << "For element " << i + 1 << ", enter the label: ";
		cin.getline(label, LEN);
		cout << "Enter the rating: ";
		cin >> rating;
		cout << "Enter 1 if this is to be a baseDMA object" << endl;
		cout << "Enter 2 if this is to be a hasDMA object" << endl;
		cout << "Enter 3 if this is to be a lacksDMA object" << endl;
		cin >> choice;
		cin.get(); 	// discard newline character
		switch (choice)
		{
			case 1:
				arr[i] = new baseDMA(label, rating);
				break;
			case 2:
				cout << "Enter the style: ";
				cin.getline(style, LEN);
				arr[i] = new hasDMA(style, label, rating);
				break;
			case 3:
				cout << "Enter color: ";
				cin.getline(color, LEN);
				arr[i] = new lacksDMA(color, label, rating);
				break;
			default:
				cout << "Unrecognized input, setting object ";
				cout << "to baseDMA";
				arr[i] = new baseDMA(label, rating);				
				break;
		}

	}
	// when loop terminates, display values
	cout << "Here's what you entered:" << endl;
	for (int i = 0; i < ArrLength; i++)
	{
		cout << "Element " << i + 1 << ":" << endl;
		arr[i]->View();
	}	

	for (int i = 0; i < ArrLength; i++)
		delete arr[i];
	return 0;
}
