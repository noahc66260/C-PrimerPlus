// pe17-6.cpp -- description here
// This is exercise 6 of chapter 17 in C++ Primer Plus 5e by Stephen Prata
// compile with emp.cpp

#include<iostream>
#include<fstream>
#include<cstdlib>
#include "emp.h"
#include<iomanip>

using namespace std;

const int MAX = 10;

void displayMenu(void);
void eatline(void);

int main(void)
{
	// On first use, the program should solicit data from user, show all entries, and save into in a file. On subsequent uses, the program should first read and display the file data, let the user add data, and show all the data. 
	abstr_emp * pc[MAX];
	cout << "You may enter of to " << MAX << " employees" << endl;
	int count = 0;
	char ch;

	// Read from employeeList.dat file
	ifstream fin;
	fin.open("employeeList.dat");
	if (fin.is_open())
	{
		int classtype;
		while((fin >> classtype).get(ch))
		{
			switch(classtype)
			{
				case abstr_emp::Employee: 
					cout << "Creating an employee object" << endl;
					pc[count] = new employee;
					pc[count++]->getall(fin);
					break;
				case abstr_emp::Manager:
					cout << "Creating an manager object" << endl;
					pc[count] = new manager;
					pc[count++]->getall(fin);
					break;
				case abstr_emp::Fink:
					cout << "Creating an fink object" << endl;
					pc[count] = new fink;
					pc[count++]->getall(fin);
					break;
				case abstr_emp::Highfink:
					cout << "Creating an highfink object" << endl;
					pc[count] = new highfink;
					pc[count++]->getall(fin);
					break;
				default:
					cerr << "It looks like an error has occurred" << endl;
					break;
			}
		}
		cout << "Here is your current employee list: " << endl;
		for (int i = 0; i < count; i++)
		{
			pc[i]->ShowAll();
			cout << endl;
		}
		fin.close();
	}

	// Allow user to enter more data
	while (count < MAX)
	{
		displayMenu();
		cin >> ch;
		eatline();
		switch (ch)
		{
			case 'a':
				pc[count] = new employee;
				pc[count]->SetAll();
				count++;
				break;
			case 'b':
				pc[count] = new manager;
				pc[count]->SetAll();
				count++;
				break;
			case 'c':
				pc[count] = new fink;
				pc[count]->SetAll();
				count++;
				break;
			case 'd':
				pc[count] = new highfink;
				pc[count]->SetAll();
				count++;
				break;
			case 'q':
				break;
			default:
				cout << "Error input not recognized" << endl;
				continue; // this should apply to while loop
				break;
		}
		if (ch == 'q')
			break;
	}

	// write data to file and display data
	ofstream fout;
	fout.open("employeeList.dat");
	if(!fout.is_open())
	{
		cerr << "Error, cannot open employeeList.dat" << endl;
		exit(EXIT_FAILURE);
	}

	cout << "Here's our updated list: " << endl;
	for(int i = 0; i < count; i++)
	{
		pc[i]->ShowAll();
		cout << endl;
		pc[i]->writeall(fout);
	}

	fout.close();
	return 0;
}

void displayMenu(void)
{
	cout << "Select one of the following:" << endl;
	cout << left;
	cout << setw(20) << "a. Employee"
		<< setw(20) << "b. Manager"
		<< endl
		<< setw(20) << "c. Fink"
		<< setw(20) << "d. Highfink"
		<< endl
		<< "(q to quit)" << endl;
}

void eatline(void)
{
	char ch;
	while(cin.get(ch) && ch != '\n')
		continue;
}
