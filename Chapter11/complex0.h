// complex0.h -- a user defined class for complex number operatons
// This is exercise 7 of chapter 11 in C++ Primer Plus by Stephen Prata
// this code is supplemented by complex0.cpp and questionSeven.cpp

#include<iostream>

#ifndef COMPLEX0_H_
#define COMPLEX0_H_

class Complex
{
private:
	double a;
	double b;
public:
	Complex(double a, double b = 0);
	Complex();
	void set(double a, double b);
	friend Complex operator+(const Complex & c1, const Complex & c2); 
	friend Complex operator-(const Complex & c1, const Complex & c2); 
	friend Complex operator*(const Complex & c1, const Complex & c2); 
	friend Complex operator*(double d, const Complex & c2); 
	friend Complex operator~(const Complex & c);
	friend std::ostream & operator<<(std::ostream & os,
		const Complex & c);
	friend std::istream & operator>>(std::istream & os, 
		Complex & c);
};

#endif
