// golf.h -- constants, and structures, and functions for golf header file
// This is exercise 1 of chapter 9 in C++ Primer Plus by Stephen Prata
// golf.h is accompanied by golf.cpp and questionOne.cpp

// golf.h - for pe9-1.cpp

// Don't I need to include the #ifndef GOLF ... thing, since 
// not doing so would cause problems if two files include golf.h?
// Hm... I guess I'll find out. 

const int Len = 40;
struct golf
{
	char fullname[Len];
	int handicap;
};

// non-interactive version:
// function sets golf structure to provided name, handicap
// using values passed as arguments to the function
void setgolf(golf & g, const char * name, int hc);

// interactive version:
// function solicits name and handicap from user
// and sets the members of g to the values entered
// returns 1 if name is entered, 0 if name is empty string
int setgolf(golf & g);

// function resets handicap to new value
void handicap(golf & g, int hc);

// function displays contents of golf structure
void showgolf(const golf & g);
