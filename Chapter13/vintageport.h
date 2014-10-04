// vintageport.h -- the VintagePort class interface
// This is exercise 4 of chapter 12 in C++ Primer Plus by Stephen Prata
// Note: this code was given as part of the problem

#ifndef VINTAGEPORT_H_
#define VINTAGEPORT_H_

#include "port.h"
class VintagePort : public Port // style necessarily = "vintage"
{
private:
	char * nickname;	// i.e., "The Noble" or "Old Velvet", etc.
	int year; 	// vintage year
public:
	VintagePort();
	VintagePort(const char * br, int b, const char * nn, int y);
	VintagePort(const VintagePort & vp);
	~VintagePort() { delete [] nickname; }
	VintagePort & operator=(const VintagePort & vp);
	virtual void Show() const;
	friend ostream & operator<<(ostream & os, const VintagePort & vp);
};

#endif
