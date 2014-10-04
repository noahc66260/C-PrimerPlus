// customerStack.cpp - customerStack class implementation
// This is exercise 5 of chapter 10 in C++ Primer Plus by Stephen Prata
// customerStack.cpp is accompanied by customerStack.h and questionFive.cpp


// do I need to include libraries? --> yes.
#include"customerStack.h"

// I believe I don't need a typedef command for Item since 
// we are importing the customerStack.h library --> you don't. 

CustomerStack::CustomerStack()
{
	top = 0;
}

bool CustomerStack::isempty() const
{
	if (0 == top)
		return true;
	else
		return false;
}

bool CustomerStack::isfull() const
{
	if (MAX == top)
		return true;
	else
		return false;
}

bool CustomerStack::push(const Item & item)
{
	if (0 == isfull())
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

bool CustomerStack::pop(Item & item)
{
	if (0 == isempty())
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}
	
