// plorg.h - definition of the Plorg class
// This is exercise 7 of chapter 10 in C++ Primer Plus by Stephen Prata
// plorg.h is accompanied by plorg.cpp and questionSeven.cpp

#ifndef PLORG_H_
#define PLORG_H_

class Plorg
{
	/*
	Class invariants:
		std::strlen(name) <= 19
	*/


private:
	enum {MAX = 20};
	char name[MAX];
	int CI;	// contentment index
public:
	Plorg(const char * name = "Plorga");
	void changeCI(int CI);
	void show(void) const; // prints name and CI to standard output
};

#endif
