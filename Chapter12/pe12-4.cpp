// pe12-4.cpp -- tests the Stack ADT class
// This is exercise 4 of chapter 12 in C++ Primer Plus by Stephen Prata
// compile with stack2.cpp 

#include<iostream>
#include "stack2.h"

inline void printStack(Stack s) {std::cout << s;}

int main()
{
	using namespace std;

	cout << "setting s1..." << endl;
	Stack s1;
	cout << "setting s2..." << endl;
	Stack s2(5);
	cout << "setting s3..." << endl;
	Stack s3(-1);
	cout << "setting s4..." << endl;
	Stack s4 = Stack(10);
	cout << "setting s5..." << endl;
	Stack s5(s4);
	cout << "setting s6..." << endl;
	Stack s6 = Stack(s3);

	cout << "s1.isempty() == " << s1.isempty() << endl;
	s1.push(10);
	s1.push(20);
	s1.push(30);

	s2 = s1;
	unsigned long int x;
	s2.pop(x);
	cout << "We pushed 10, 20, and 30 into s1" << endl;
	cout << "We assigned s2 to s1" << endl;
	cout << "s2.pop(x), x = " << x << endl;

	cout << "s1: " << endl;
	printStack(s1);
	cout << "s2: " << endl << s2;

	return 0;
}
