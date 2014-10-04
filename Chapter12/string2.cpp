// string2.cpp -- String class methods
// This is exercise 2 of chapter 12 in C++ Primer Plus by Stephen Prata

#include <cstring>                 // string.h for some
#include "string2.h"               // includes <iostream>
using std::cin;
using std::cout;
#include <cctype>
#include <cstring>

// initializing static class member

int String::num_strings = 0;

// static method
int String::HowMany()
{
    return num_strings;
}

// class methods
String::String(const char * s)     // construct String from C string
{
    len = std::strlen(s);          // set size
    str = new char[len + 1];       // allot storage
    std::strcpy(str, s);           // initialize pointer
    num_strings++;                 // set object count
}

String::String()                   // default constructor
{
    len = 4;
    str = new char[1];
    str[0] = '\0';                 // default string
    num_strings++;
}

String::String(const String & st)
{
    num_strings++;             // handle static member update
    len = st.len;              // same length
    str = new char[len + 1];  // allot space
    std::strcpy(str, st.str);  // copy string to new location
}

String::~String()                     // necessary destructor
{
    --num_strings;                    // required
    delete [] str;                    // required
}

void String::stringlow()
{
	using std::isupper;
	using std::tolower;

	int i = 0;
	while (str[i] != '\0')
	{
		if (isupper(str[i]))
			str[i] = tolower(str[i]);
		i++;
	}
}

void String::stringup()
{
	using std::islower;
	using std::toupper;

	int i = 0;
	while (str[i] != '\0')
	{
		if (islower(str[i]))
			str[i] = toupper(str[i]);
		i++;
	}
}

int String::has(const char c) const
{
	int i = 0;
	int count = 0;
	while (str[i] != '\0')
	{
		if (c == tolower(str[i]) || c == toupper(str[i]))
			count++;
		i++;
	}
	return count;
}

// overloaded operator methods    

    // assign a String to a String
String & String::operator=(const String & st)
{
    if (this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

    // assign a C string to a String
String & String::operator=(const char * s)
{
    delete [] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

    // read-write char access for non-const String
char & String::operator[](int i)
{
    return str[i];
}

    // read-only char access for const String
const char & String::operator[](int i) const
{
    return str[i];
}

// overloaded operator friends

bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
    return st2.str < st1.str;
}

bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

    // simple String output
ostream & operator<<(ostream & os, const String & st)
{
    os << st.str;
    return os; 
}

    // quick and dirty String input
istream & operator>>(istream & is, String & st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is; 
}

String operator+(const String &st1, const String &st2)
{	
	using std::strlen;
	using std::strcat;
	using std::strcpy;

	int length = strlen(st1.str) + strlen(st2.str) + 1;
	char * temp = new char[length];
	strcpy(temp, st1.str);
	String s(strcat(temp, st2.str));
	delete [] temp;
	return s;
}

String operator+(const char * st1, const String &st2)
{
	return String(st1) + st2;
}

String operator+(const String &st1, const char * st2)
{
	return st2 + st1;
}
