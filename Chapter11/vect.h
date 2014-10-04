// vect.h -- Vector class with <<, mode state
// Note: this is listing 11.13 in Stephen Prata's C++ Primer Plus

#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
namespace VECTOR
{
	class Vector
	{
	private:
		double x;
		double y;
		double mag;
		double ang;
		char mode;
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(double n1, double n2, char form = 'r');
		void set(double n1, double n2, char form = 'r');
		~Vector();
		double xval() const {return x;}
		double yval() const {return y;}
		double magval() const {return mag;}
		double angval() const {return ang;}
		void polar_mode();
		void rect_mode();
		Vector operator+(const Vector & b) const;
		Vector operator-(const Vector & b) const;
		Vector operator-() const;
		Vector operator*(double n) const;
		friend Vector operator*(double n, const Vector & a);
		friend std::ostream & operator<<(std::ostream & os, const Vector & v);
	};
}
#endif
