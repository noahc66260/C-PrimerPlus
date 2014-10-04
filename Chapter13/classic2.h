// classic2.h -- interface of the Classic class with dynamic memory
// This is exercise 2 of chapter 12 in C++ Primer Plus by Stephen Prata

#ifndef CLASSIC_H_
#define CLASSIC_H_

#include "cd2.h"

class Classic : public Cd
{
private:
	char * primary_work;
public:
	Classic();
	Classic(const char * primary, Cd & d);
	Classic(const char * primary, const char * s1, 
		const char * s2, int n, double x);
	Classic(const Classic & c);
	~Classic();
	virtual void Report() const;
	Classic & operator=(const Classic & c);
};

#endif
