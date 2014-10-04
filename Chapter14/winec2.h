// winec2.h -- interface for the Wine class
// This is exercise 1 of chapter 14 in C++ Primer Plus by Stephen Prata

#ifndef WINEC2_H_
#define WINEC2_H_

#include<iostream>
#include<valarray>
#include"pair.h"

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine : private PairArray, private std::string
{
private:
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
