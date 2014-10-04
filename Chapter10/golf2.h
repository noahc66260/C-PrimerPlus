// golf2.h -- the golf class header file
// This is exercise 3 of chapter 10 in C++ Primer Plus by Stephen Prata
// golf2.h is accompanied by golf2.cpp and questionThree.cpp

#ifndef GOLF_H_
#define GOLF_H_

const int Len = 40;
class Golf
{
	/*
	Class invariants: 
		every player must have a name			  
	*/


private:
	char fullname[Len];
	int handicap;
public:
	// default constructor
	Golf();

	// explicit constructor:
	// function sets golf structure to provided name, handicap
	// using values passed as arguments to the function
	Golf(const char * fullname, int handicap);

	// interactive version:
	// function solicits name and handicap from user
	// and sets the members of g to the values entered
	// returns 1 if name is entered, 0 if name is empty string
	int setgolf();

	// function resets handicap to new value
	void setHandicap(int handicap);

	// function displays contents of golf structure
	void showgolf() const;
};

#endif
