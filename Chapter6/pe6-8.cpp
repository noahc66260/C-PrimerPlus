// pe6-8.cpp -- opens a text file, reads it character-by-character to the end of the file, and reports the number of characters in the file.
// This is exercise 8 of chapter 9 in C++ Primer Plus by Stephen Prata

#include<iostream>
#include<fstream>	// for ifstream object
#include<cstdlib>	// for exit() and EXIT_FAILURE values
const int SIZE = 100;

int main(void)
{
	using namespace std; 

	// create ifstream object
	ifstream inFile; 	// inFile an ifstream object
	char file[SIZE];

	// Prompt user to enter file name
	cout << "Enter the file name you wish to open, including the extension: ";
	cin.getline(file, SIZE);

	// Open file and check that file opened correctly
	inFile.open(file);
	if (!inFile.is_open())
	{
		cout << "cout not open the file " << file << endl;
		cout << "Program terminating" << endl;		
		exit(EXIT_FAILURE);
	}

	// read characters until EOF is reached
	char ch;
	inFile >> ch;
	int characters = 0;
	while (!inFile.eof())
	{
		characters++;
		inFile >> ch;
	}

	// display the number of characters
	cout << characters << " characters in " << file << endl;

	// close file
	inFile.close();
	
	return 0;
}
