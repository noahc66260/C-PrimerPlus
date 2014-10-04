// pe13-2.cpp -- description here
// This is exercise 2 of chapter 12 in C++ Primer Plus by Stephen Prata
// Note: This code was given by the book, the question is really
// to write classic2.h, classic2.cpp, and cd2.cpp
// compile with classic2.cpp and cd2.cpp

#include<iostream>
using namespace std;
#include "classic2.h" 	// which will contain #include cd.h
void Bravo(const Cd & disk);
int main(void)
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano sonata in b flat, Fantasia in C", "Alfred Brendel", "Phillips", 2, 57.17); 
	Cd * pcd = &c1;

	cout << "Using object directly:\n";
	c1.Report(); 	// use Cd method
	c2.Report(); 	// use Classic method
	
	cout << "Using type cd * pointer to objects:\n";
	pcd->Report(); 	// use Cd method for cd object
	pcd = &c2;
	pcd->Report(); 	// use Classic method for classic object
	
	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);

	cout << "Testing assignment: \n";
	Classic copy;
	copy = c2;
	copy.Report();

	return 0;
}

void Bravo(const Cd & disk)
{
	disk.Report();
}
