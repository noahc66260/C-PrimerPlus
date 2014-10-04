// stack2.cpp -- implementation of Stack ADT class (stack2.h)
// This is exercise 4 of chapter 12 in C++ Primer Plus by Stephen Prata
// compile with pe12_4.cpp

#include "stack2.h"
#include<iostream> 	// for std::cerr

Stack::Stack(int n)	// creates stack with n elements
{
    if (n < 1)
    {
        std::cerr << "Error. Argument must be a positive integer. "
                  << "Setting n to 10." << std::endl;
        n = 10;
    }
    pitems = new Item[n];
    size = top = 0;
}

Stack::Stack(const Stack & st)
{
    pitems = new Item[st.size];
    for (int i = 0; i < st.size; i++)
        pitems[i] = (st.pitems)[i];
    size = st.size;
    top = st.top;
}

Stack::~Stack()
{
    delete [] pitems;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}

bool Stack::push(const Item & item)   
{
    if (top < MAX)
    {
        pitems[top++] = item;
        size++;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item & item)
{
    if (top > 0)
    {
        item = pitems[--top];
        size--;
        return true;
    }
    else
        return false; 
}

Stack & Stack::operator=(const Stack & st)
{
    if (this == &st)
        return *this;
    delete [] pitems;
    size = st.size;
    top = st.top;
    pitems = new Item[size];
    for (int i = 0; i < size; i++)
        pitems[i] = (st.pitems)[i];
    return *this;
}

std::ostream & operator<<(std::ostream & os, const Stack & s)
{
	using std::endl;
	for (int i = 0; i < s.top; i++)
	{
		os << "item " << i + 1 << ": " << (s.pitems)[i] << endl;
	}
	return os;
}
