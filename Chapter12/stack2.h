// stack2.h -- Stack ADT (a modified version of listing 10.10)
// Note: this code was given in the problem
// This is exercise 4 of chapter 12 in C++ Primer Plus by Stephen Prata
#ifndef STACK_H_
#define STACK_H_

#include<iostream>

typedef unsigned long Item;

class Stack
{
private:
    enum {MAX = 10};    // constant specific to class
    Item * pitems;    // holds stack items
    int size;			// number of elements in the stack
    int top;            // index for top stack item
public:
    Stack(int n = 10);	// creates stack with n elements
    Stack(const Stack & st);
    ~Stack();
    bool isempty() const;
    bool isfull() const;
    // push() returns false if stack already is full, true otherwise
    bool push(const Item & item);   // add item to stack
    // pop() returns false if stack already is empty, true otherwise
    bool pop(Item & item);          // pop top into item
    Stack & operator=(const Stack & st);
    friend std::ostream & operator<<(std::ostream & os, const Stack & s);
};

#endif
