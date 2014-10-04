// pe12-1.cpp -- tests the Cow class
// This is exercise 1 of chapter 12 in C++ Primer Plus by Stephen Prata
// compile with questionOne.cpp

#include<iostream>
#include "Cow.h"

inline void ShowCow2(Cow c) {c.ShowCow();}

int main()
{
	using namespace std;
	cout << "Let's create object 1" << endl;
	Cow c1;
	cout << "Let's create object 2" << endl;
	Cow c2 = Cow("Melinda", "Tennis", 130.0);
	cout << "Let's create object 3" << endl;
	Cow c3 = c2;
	cout << "Let's create object 4" << endl;
	Cow c4("Karina", "Badminton", 125.0);
	cout << "Let's create object 5" << endl;
	Cow c5 = Cow(c3);
	cout << "Let's create object 6" << endl;
	Cow c6(c4);
	cout << "Let's create object 7" << endl;
	Cow * pc = new Cow;
	*pc = c6;

	cout << "Let's see our cows: " << endl;
	c1.ShowCow();
	c2.ShowCow();
	c3.ShowCow();
	c4.ShowCow();
	c5.ShowCow();
	c6.ShowCow();
	pc->ShowCow();

	cout << "Let's see our cows AGAIN!" << endl;
	ShowCow2(c1);
	ShowCow2(c2);
	ShowCow2(c3);	
	ShowCow2(c4);
	ShowCow2(c5);
	ShowCow2(c6);	
	ShowCow2(*pc);

	return 0;
}
