// pair.h -- interface and implementation of the pair class
// This is exercise 2 of chapter 14 in C++ Primer Plus 5e by Stephen Prata
// Note: This code is the first part of listing 14.19

#ifndef PAIR_H_
#define PAIR_H_

#include<iostream>
#include<string>

template<class T1, class T2>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	T1 & first();
	T2 & second();
	T1 first() const { return a; }
	T2 second() const { return b; }
	Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) { }
	Pair() {}
};

template<class T1, class T2>
T1 & Pair<T1,T2>::first()
{
	return a;
}

template<class T1, class T2>
T2 & Pair<T1,T2>::second()
{
	return b;
}

#endif

