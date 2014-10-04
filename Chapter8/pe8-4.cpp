// pe8-4.cpp -- uses a function to dynamically allocate memory to
// copy a string and gives pointer to said string to a structure.
// This is exercise 4 of chapter 10 in C++ Primer Plus by Stephen Prata

#include<iostream>
using namespace std;
#include<cstring> 	// for strlen(), strcpy()
struct stringy
{
	char * str;
	int ct;
};

// prototypes for set(), show(), and show()
void set(stringy & x, char str[]);
void show(const stringy & x, int repeat = 1);
void show(const char str[], int repeat = 1);

int main(void)
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	
	set(beany, testing);	// first argument is a reference,
		// allocates space to hold copy of testing,
		// sets str member of beany to point to the 
		// new block, copies testing to new block,
		// and sets ct member of beany
	show(beany); 	// prints member string once
	show(beany, 2); // prints member string twice
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);		// prints string once
	show(testing, 3); 	// prints testing string thirce
	show("Done!");

	delete [] beany.str;
	return 0;
}


// create dynamic array of char, copy string to location and assign
// location to structure
void set(stringy & x, char str[])
{
	int length = strlen(str);
	char * pstr = new char[length + 1];
	strcpy(pstr, str);

	x.str = pstr;
	x.ct = length;
	return;
}

// prints member string a variable number of times
void show(const stringy & x, int repeat)
{
	for (int i = 0; i < repeat; i++)
		cout << x.str << endl;
	return;
}

// prints string a variable number of times
void show(const char str[], int repeat)
{
	for (int i = 0; i < repeat; i++)
		cout << str << endl;
	return;
}
