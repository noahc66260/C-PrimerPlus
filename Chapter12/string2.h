// string2.h -- an upgraded version of string1.h from C++ Primer Plus
// This is exercise 2 of chapter 12 in C++ Primer Plus by Stephen Prata

#include <iostream>
using std::ostream;
using std::istream;

#ifndef STRING2_H_
#define STRING2_H_
class String
{
private:
    char * str;             // pointer to string
    int len;                // length of string
    static int num_strings; // number of objects
    static const int CINLIM = 80;  // cin input limit
public:
// constructors and other methods
    String(const char * s); // constructor
    String();               // default constructor
    String(const String &); // copy constructor
    ~String();              // destructor
    int length () const { return len; }
    void stringlow();
    void stringup();
    int has(const char c) const;
		// returns number of occurences of 'c' in String
// overloaded operator methods    
    String & operator=(const String &);
    String & operator=(const char *);
    char & operator[](int i);
    const char & operator[](int i) const;
// overloaded operator friends
    friend bool operator<(const String &st1, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st1, const String &st2);
    friend ostream & operator<<(ostream & os, const String & st);
    friend istream & operator>>(istream & is, String & st);
    friend String operator+(const String &st1, const String &st2);
    friend String operator+(const char * st1, const String &st2);
    friend String operator+(const String &st1, const char * st2);
// static function
    static int HowMany();
};
#endif
