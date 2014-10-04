// vintageport.cpp -- the VintagePort class interface
// This is exercise 4 of chapter 12 in C++ Primer Plus by Stephen Prata

#include<iostream>
#include<cstring>
#include "vintageport.h"
using std::ostream;

VintagePort::VintagePort() : Port("The Noble", "Vintage")
{
	nickname = NULL;
	year = 1900;
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y)
	: Port(br, "Vintage", b)
{
	nickname = new char[strlen(nn) + 1];
	strcpy(nickname, nn);
	year = y;
}

VintagePort::VintagePort(const VintagePort & vp) : Port(vp)
{
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;	
}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
	if (this == &vp)
		return *this;
	else
	{
		Port::operator=(vp);
		delete [] nickname;
		nickname = new char[strlen(vp.nickname) + 1];
		strcpy(nickname, vp.nickname);
		year = vp.year;
	}
	return *this;
}

void VintagePort::Show() const
{
	using std::cout;
	using std::endl;

	Port::Show();
	cout << "Nickname: " << nickname << endl;
	cout << "Year: " << year << endl;	
}

ostream & operator<<(ostream & os, const VintagePort & vp)
{
	os << (const Port &) vp;
	if (NULL == vp.nickname)
		os << ", " << vp.year;
	else
		os << ", " << vp.nickname << ", " << vp.year;
	return os;
}

