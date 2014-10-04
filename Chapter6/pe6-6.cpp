// pe6-6.cpp -- tracks the contributions by storing data in an array of structures. Program then displays donors.
// This is exercise 6 of chapter 6 in C++ Primer Plus by Stephen Prata

#include<iostream>
	
using namespace std;		

const int Contribution = 10000;
struct donors
{
	string name;
	double amount;
};

int main(void)
{
	// ask the user for number of donors
	cout << "How many donors are there? ";	
	int numberDonors;
	cin >> numberDonors;
	cin.get();

	// dynamically create array of that size of structures

	donors * list = new donors[numberDonors];
	int donationSizes[numberDonors];

	// for loop to initialize structure

	for (int i = 0; i < numberDonors; i++)
	{
		cout << "Donor number " << i + 1 << endl
		     << "Name: ";
		getline(cin, (list + i)->name, '\n');
		cout << "Contribution: ";
		cin >> (list + i)->amount;
		cin.get();
	
		// Store information on if donation surpasses Contribution
		if ((list + i)->amount >= Contribution)
			donationSizes[i] = 1;
		else
			donationSizes[i] = 0;
	}	
	
	// for loop to list highest donors and contributions (Grand Patrons), print none if there are 0 members
	cout << "List of Grand Patrons: " << endl;
	int counter = 0; 				// to determine if there are any patrons in either group	
	for (int i = 0; i < numberDonors; i++)
	{
		if (donationSizes[i] == 1)
		{
			cout << (list + i)->name << ", $" << (list + i)->amount << endl;
			counter = 1;
		}
	}

	// print "None" if no patrons are in list of Grand Patrons
	if (!counter)
			cout << "None" << endl;

	// for loop to list remaining donors (Patrons), print none there are 0 members
	counter = 0;
	cout << "List of remaining patrons:" << endl;
	for (int i = 0; i < numberDonors; i++)
	{
		if (donationSizes[i] == 0)
		{
			cout << (list + i)->name << endl;
			counter = 1;
		}
	}

	// print "None" if no people are in list of remaining patrons
	if (!counter)
			cout << "None" << endl;
	
	return 0;
}
