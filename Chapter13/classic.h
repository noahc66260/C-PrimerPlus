// classic.h -- interface of the Classic class
// This is exercise 1 of chapter 12 in C++ Primer Plus by Stephen Prata

#ifndef CLASSIC_H_
#define CLASSIC_H_

#include "cd.h"

class Classic : public Cd
{
private:
	enum {len_primary = 40};
	char primary_work[len_primary];
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
