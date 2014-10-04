// move.cpp - implementation of the Move class
// This is exercise 6 of chapter 10 in C++ Primer Plus by Stephen Prata
// move.cpp is accompanied by move.h and questionSix.cpp

#include<iostream>
#include "move.h"

Move::Move(double a, double b)
{
	x = a;
	y = b;
}


void Move::showmove() const
{
	using std::cout;
	using std::endl;

	cout << "x = " << this->x << endl;
	cout << "y = " << this->y << endl;
	return;
}


Move Move::add(const Move & m) const
{
	Move s(m.x + this->x, m.y + this->y);
	return s;
}
// this function adds x of m to x of invoking object to get new x,
// adds y of m to y of invoking object to get new y, creates a new
// move object initialized to new x, y values and returns it 


void Move::reset(double a, double b) 	// resets x, y to a, b
{
	x = a;
	y = b;
	return;
}
