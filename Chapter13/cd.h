// cd.h -- interface of the Cd class
// This is exercise 1 of chapter 12 in C++ Primer Plus by Stephen Prata
// Note: This code was given by the book, the question is really
// to write classic.h, classic.cpp, and cd.cpp

#ifndef Cd_H_
#define Cd_H_

// base class
class Cd
{
private:
	enum {len_performer = 50, len_label = 20};
	char performers[len_performer];
	char label[len_label];
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

