// Cow.cpp -- implementation of the Cow class
// This is exercise 1 of chapter 12 in C++ Primer Plus by Stephen Prata
// compile with questionOne.cpp

#include "Cow.h"		// interface for Cow class
#include<cstring>		// for strlen(), strncpy(), and strcpy()
#include<iostream> 	// for cout and endl

Cow::Cow()
{
	using std::cout;
	using std::endl;

	name[0] = '\0';
	hobby = NULL;
	weight = 0;

	cout << "Default constructor used" << endl;
}

Cow::Cow(const char * nm, const char * ho, double wt)
{
	using std::strncpy;
	using std::strcpy;
	using std::strlen;
	using std::cout;
	using std::endl;

	strncpy(name, nm, 20);
	name[19] = '\0';
	hobby = new char[strlen(ho) + 1];
	strcpy(hobby, ho);
	if (wt > 0)
		weight = wt;
	else 
		weight = 0;

	cout << "Explicit constructor used to create " << name << endl;
}

Cow::Cow(const Cow & c)
{
	using std::strcpy;
	using std::strlen;
	using std::cout;
	using std::endl;
	
	strcpy(name, c.name);
	if (NULL == c.hobby)
		hobby = NULL;
	else
	{
		hobby = new char[strlen(c.hobby) + 1];
		strcpy(hobby, c.hobby);
	}	
	weight = c.weight;

	cout << "Copy constructor used to create " << name << endl;
}

Cow::~Cow()
{
	using std::cout;
	using std::endl;

	delete [] hobby;
	cout << name << " destroyed" << endl;
}

Cow & Cow::operator=(const Cow & c)
{
	using std::strcpy;
	using std::strlen;
	using std::cout;
	using std::endl;

	if (this == &c)
		return *this;
	
	strcpy(name, c.name);
	if (NULL == c.hobby)
		hobby = NULL;
	else
	{
		hobby = new char[strlen(c.hobby) + 1];
		strcpy(hobby, c.hobby);
	}	
	weight = c.weight;

	cout << "Assignment operator used on " << name << endl;
	return *this;
}

void Cow::ShowCow() const
{
	using std::cout;
	using std::endl;

	cout << "Name: " << name << endl;
	cout << "Hobby: " << (NULL == hobby ? "NULL" : hobby) << endl;
	cout << "Weight: " << weight << endl;
}
