// pe7-8.cpp -- an exercise in using structure values and structure pointers as function arguments
// This is exercise 8 of chapter 7 in C++ Primer Plus by Stephen Prata

#include<iostream>
#include<cstring>
using namespace std;

const int SLEN = 30;
struct student
{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

// function prototypes
int getinfo(student pa[], int n);
void display1(student st);
void display2(const student * ps);
void display3(const student pa[], int n);

int main(void)
{
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')
		continue;
	
	student * ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete [] ptr_stu;
	cout << "Done\n";
	return 0;
}

// getinfo() solicits and stores data about students.
int getinfo(student pa[], int n)
{
	cout << "You may enter the information of up to " << n << " students." << endl;
	int count;
	for (count = 0; count < n; count++)
	{
		cout << "Student " << count + 1 << ":" << endl;
		cout << "Enter his/her full name (or enter nothing when finished): ";
		cin.get(pa[count].fullname, 30);
	
		// exit loop if blank line is entered for the name of a student
		if (0 == strlen(pa[count].fullname))
			break;
		else
			// discard extra input
			while (cin.get() != '\n')
				continue;
			cout << "Enter his/her hobby: ";
			cin.get(pa[count].hobby, 30);
			while (cin.get() != '\n')	// discard extra input
				continue;
			cout << "Enter his/her OOP level: ";
			cin >> pa[count].ooplevel;
			cin.get();			// discard newline character
	}
	return count;
}

// display1() takes a student structure as an argument and displays its contents
void display1(student st)
{
	cout << "Full name: " << st.fullname << endl;
	cout << "Hobby: " << st.hobby << endl;
	cout << "OOP Level: " << st.ooplevel << endl;
	return;
}

// display2() takes the address of student structure as an argument and displays the structure's contents
void display2(const student * ps)
{
	cout << "Full name: " << ps->fullname << endl;
	cout << "Hobby: " << ps->hobby << endl;
	cout << "OOP Level: " << ps->ooplevel << endl;
	return;
}

// display3() takes the address of the first element of an array of student structures and the number of array elements as arguments and displays the contents of the structures
void display3(const student pa[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		cout << "Student #" << i + 1 << ":" << endl;
		display2(pa + i);
	}
	cout << endl;
	return;
}
















