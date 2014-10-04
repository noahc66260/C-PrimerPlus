// pe11-2.cpp -- modified version of vect.cpp
// This is exercise 2 of chapter 11 in C++ Primer Plus by Stephen Prata
// see vect.cpp or listing 11.14 in C++ Primer Plus for the original file

#include<cmath>
#include "vect2.h" 	// includes <iostream>
using std::sin;
using std::cos;
using std::atan2;
using std::cout;

namespace VECTOR
{

	const double Rad_to_deg = 57.2957795130823;

	// public methods
	Vector::Vector()
	{
		x = y = 0.0;
		mode = 'r';
	}

	// construct vector from rectangular coordinates if mode is 'r'
	// (the default). Or construct vector from polar coordinates if
	// the mode is 'p'
	Vector::Vector(double n1, double n2, char form)
	{
		mode = form;
		if (form == 'r')
		{
			x = n1;
			y = n2;
		}
		else if (form == 'p')
		{
			double mag = n1;
			double ang = n2 / Rad_to_deg;
			x = mag * cos(ang);
			y = mag * sin(ang);
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			x = y = 0.0;
			mode = 'r';
		}
	}

	// set vector from rectangular coordinates if form is 'r'
	// (the default) or else from polar coordinates if form is 'p'
	void Vector::set(double n1, double n2, char form)
	{
		mode = form;
		if (form == 'r')
		{
			x = n1; 
			y = n2;
		}
		else if (form == 'p')
		{
			double mag = n1;
			double ang = n2 / Rad_to_deg;
			x = mag * cos(ang);
			y = mag * sin(ang);
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			x = y = 0.0;
			mode = 'r';
		}
	}

	Vector::~Vector()
	{
	}

	double Vector::magval() const
	{
		return sqrt(x*x + y*y);
	}

	double Vector::angval() const
	{
		if (x == 0.0 && y == 0.0)
				return 0.0;
		else
				return atan2(y,x)*Rad_to_deg;
	}

	void Vector::polar_mode()
	{
		mode = 'p';
	}

	void Vector::rect_mode()
	{
		mode = 'r';
	}

	// operator overloading
	// add two vectors
	Vector Vector::operator+(const Vector & b) const
	{
		return Vector(x + b.x, y + b.y);
	}
	
	// subtract Vector b from a
	Vector Vector::operator-(const Vector & b) const
	{
		return Vector(x - b.x, y - b.y);
	}

	// reverse sign of Vector
	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}

	// multiply vector by n
	Vector Vector::operator*(double n) const
	{
		return Vector(n * x, n * y);
	}

	// friend methods
	// multiply n by Vector a
	Vector operator*(double n, const Vector & a)
	{
		return a * n;
	}

	// display rectangular coordinates if mode is r, 
	// else display polar coordinates if mode is p
	std::ostream & operator<<(std::ostream & os, const Vector & v)
	{
		if (v.mode == 'r')
			os << "(x,y) = (" << v.x << ", " << v.y << ")";
		else if (v.mode == 'p')
		{
			double mag = sqrt(v.x*v.x + v.y*v.y);
			double ang;
			if (v.x == 0.0 && v.y == 0.0)
				ang = 0.0;
			else
				ang = atan2(v.y,v.x);
			os << "(m,a) = (" << mag << ", "
			   << ang * Rad_to_deg << ")";
		}
		else
			os << "Vector object mode is invalid";
		return os;
	}

} // end namespace VECTOR
