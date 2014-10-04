// dma2.cpp -- implementation of ABC for DMA objects
// This is exercise 3 of chapter 12 in C++ Primer Plus by Stephen Prata

#include "dma2.h"
#include <cstring>

abcDMA::abcDMA(const char * l, int r)
{
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

abcDMA::abcDMA(const abcDMA & a)
{
    label = new char[std::strlen(a.label) + 1];
    std::strcpy(label, a.label);
    rating = a.rating;
}

void abcDMA::View() const
{
	using std::cout;
	using std::endl;

	cout << "Label: " << label << endl;
	cout << "Rating: " << rating << endl;
}

abcDMA::~abcDMA()
{
    delete [] label;
}

abcDMA & abcDMA::operator=(const abcDMA & a)
{
    if (this == &a)
        return *this;
    delete [] label;
    label = new char[std::strlen(a.label) + 1];
    std::strcpy(label, a.label);
    rating = a.rating;
    return *this;	
}

std::ostream & operator<<(std::ostream & os, 
		const abcDMA & rs)
{
    os << "Label: " << rs.label << std::endl;
    os << "Rating: " << rs.rating << std::endl;
	return os;	
}


// baseDMA methods
baseDMA::baseDMA(const char * l, int r) : abcDMA(l, r)
{
}

baseDMA::baseDMA(const baseDMA & rs) : abcDMA(rs)
{
}

baseDMA::~baseDMA()
{
}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
	abcDMA::operator=(rs);
	return *this;	// I am unsure if this will work
}

void baseDMA::View() const
{
	using std::cout;
	using std::endl;

	cout << "baseDMA object" << endl;
	cout << "Label: " << showLabel() << endl;
	cout << "Rating: " << showRating() << endl;
}

std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
	os << (const abcDMA &) rs;
	return os;
}

// lacksDMA methods
lacksDMA::lacksDMA(const char * c, const char * l, int r)
    : abcDMA(l, r)
{
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

void lacksDMA::View() const
{
	using std::cout;
	using std::endl;

	cout << "lacksDMA object" << endl;
	abcDMA::View();
	cout << "Color: " << color << endl;
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & ls)
{
    //os << (const baseDMA &) ls; // What?!
	os << (const abcDMA &) ls;
    os << "Color: " << ls.color << std::endl;
    return os;
}

// hasDMA methods
hasDMA::hasDMA(const char * s, const char * l, int r)
         : abcDMA(l, r)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs)
         : abcDMA(hs)  // invoke base class copy constructor
{
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if (this == &hs)
        return *this;
    abcDMA::operator=(hs);  // copy base portion
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}

void hasDMA::View() const
{
	using std::cout;
	using std::endl;

	cout << "hasDMA object" << endl;
	abcDMA::View();
	cout << "Style: " << style << endl;
}
    
std::ostream & operator<<(std::ostream & os, const hasDMA & hs)
{
    os << (const abcDMA &) hs;
    os << "Style: " << hs.style << std::endl;
    return os;
}
