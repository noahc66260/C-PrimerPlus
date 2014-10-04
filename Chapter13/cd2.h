// cd2.h -- interface of the Cd class with dynamic memory
// This is exercise 2 of chapter 12 in C++ Primer Plus by Stephen Prata

#ifndef Cd_H_
#define Cd_H_

#include<iostream>

// base class
class Cd
{
private:
	char * performers;
	char * label;
	int selections;	// number of selections
	double playtime; 	// playing time in minutes
public:
	Cd(const char * s1, const char * s2, int n, double x);
	Cd(const Cd & d);
	Cd();
	virtual ~Cd();
	virtual void Report() const; 	// reports all CD data
	Cd & operator=(const Cd & d);
};

#endif

