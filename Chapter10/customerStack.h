// customerStack.h - customerStack class header file
// This is exercise 5 of chapter 10 in C++ Primer Plus by Stephen Prata
// customerStack.h is accompanied by customerStack.cpp and questionFive.cpp

#ifndef CUSTOMERSTACK_H_
#define CUSTOMERSTACK_H_

struct customer
{
	char fullname[35];
	double payment;
};

typedef customer Item;

class CustomerStack
{
	/*
	Class invariants:
		(top == 0 || top > 0) && top <= MAX
	*/

private:
	enum {MAX = 10}; 
	Item items[MAX]; 
	int top;	// index for top stack item
public:
	CustomerStack();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item & item);
	bool pop(Item & item);
};

#endif
