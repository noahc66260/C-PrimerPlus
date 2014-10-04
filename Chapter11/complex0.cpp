// complex0.cpp -- implementation of the complex0.h file, Complex class
// This is exercise 7 of chapter 11 in C++ Primer Plus by Stephen Prata
// this code is supplemented by complex0.h and questionSeven.cpp

#include<iostream>
using std::cout;
#include "complex0.h"

Complex::Complex(double a, double b)
{
	this->a = a;
	this->b = b;
}

Complex::Complex()
{
	a = 0;
	b = 0;
}

void Complex::set(double a, double b)
{
	this->a = a;
	this->b = b;
}

Complex operator+(const Complex & c1, const Complex & c2) 
{
	Complex sum;
	sum.a = c1.a + c2.a;
	sum.b = c1.b + c2.b;
	return sum;
}

Complex operator-(const Complex & c1, const Complex & c2)
{
	Complex diff;
	diff.a = c1.a - c2.a;
	diff.b = c1.b - c2.b;
	return diff;
}

Complex operator*(const Complex & c1, const Complex & c2)
{
	Complex prod;
	prod.a = c1.a*c2.a - c1.b*c2.b;
	prod.b = c1.a*c2.b + c1.b*c2.a;
	return prod;
}

Complex operator*(double d, const Complex & c)
{
	Complex prod;
	prod.a = c.a * d;
	prod.b = c.b * d;
	return prod;
}

Complex operator~(const Complex & c)
{
	Complex conj;
	conj.a = c.a;
	conj.b = -c.b;
	return conj;
}

std::ostream & operator<<(std::ostream & os, const Complex & c)
{
	os << "(" << c.a << ", " << c.b << "i)";
	return os;
}

std::istream & operator>>(std::istream & is, Complex & c)
{
	is >> c.a;
	is >> c.b;
	return is;
}
