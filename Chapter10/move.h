// move.h - definition of the Move class
// This is exercise 6 of chapter 10 in C++ Primer Plus by Stephen Prata
// move.h is accompanied by move.cpp and questionSix.cpp

#ifndef MOVE_H_
#define MOVE_H_

class Move
{
private:
	double x;
	double y;
public:
	Move(double a = 0, double b = 0); 	//sets x, y to a, b
	void showmove() const;
	Move add(const Move & m) const;
// this function adds x of m to x of invoking object to get new x,
// adds y of m to y of invoking object to get new y, creates a new
// move object initialized to new x, y values and returns it 
	void reset(double a = 0, double b = 0); // resets x, y to a, b
};

#endif
