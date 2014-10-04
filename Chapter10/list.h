// list.h - definition of the List class which is an ADT
// This is exercise 8 of chapter 10 in C++ Primer Plus by Stephen Prata
// list.h is accompanied by list.cpp and questionEight.cpp

#ifndef LIST_H_
#define LIST_H_

typedef double Item;

class List
{
private:
	enum {MAX = 10};
	Item items[MAX];
	int index;
public:
	List();
	void add(const Item & item);
	bool isEmpty(void) const;
	bool isFull(void) const;
	void visit(void (*pf)(Item & item));
	int numberOfItems(void) const {return index;}
	void printList(void) const;
};

#endif
