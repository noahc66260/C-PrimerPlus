// winec.h -- interface for the Wine class
// This is exercise 1 of chapter 14 in C++ Primer Plus by Stephen Prata

#ifndef WINEC_H_
#define WINEC_H_

#include<iostream>
#include<valarray>

class Wine
{
private:
	typedef std::valarray<int> ArrayInt;
	typedef std::pair<ArrayInt, ArrayInt> PairArray;
	std::string label;
	PairArray data;	// contains data on vintage years and bottles
	int years; // the numbers of years we have data from
public:
	Wine(const char * l, int y, const int yr[], const int bot[]);
	Wine(const char * l, int y);
	~Wine();
	void Show() const;
	void GetBottles();
	const std::string & Label() const;
	int sum() const;
};

#endif
