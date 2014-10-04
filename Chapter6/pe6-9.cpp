// pe6-9.cpp -- tracks the contributions by storing data in an array of structures. Program then displays donors. Data is taken from a separate file.
// This is exercise 9 of chapter 6 in C++ Primer Plus by Stephen Prata

#include<iostream>
#include<fstream>	// for ifstream object
#include<cstdlib>	// for exit() and EXIT_FAILURE values
const int SIZE = 100;
	
using namespace std;		

const int Contribution = 10000;
struct donors
{
	string name;
	double amount;
};

int main(void)
{
	ifstream inFile;
	cout << "Enter the file that the donor information is stored. Include the extension: " << endl;
	char file[SIZE]; 
	cin.getline(file, SIZE);
	
	inFile.open(file);
	if (!inFile.is_open())
	{
		cout << "cout not open the file " << file << endl;
		cout << "Program terminating" << endl;		
		exit(EXIT_FAILURE);
	}

	// extract number of donors from first line
	int numberDonors;
	inFile >> numberDonors;
	inFile.get(); 

	// create dynamic array of structures
	donors * list = new donors[numberDonors];
	int donationSizes[numberDonors];	

	// for loop to get names and donations from the file
	for (int i = 0; i < numberDonors; i++)
	{
		getline(inFile, (list + i)->name, '\n');
		inFile >> (list + i)->amount;
		inFile.get();
	
		// Store information if donation surpasses Contribution
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
