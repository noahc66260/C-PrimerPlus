// stock3.h - stock2.h upgraded
// Note: this is a modified version of listing 10.7
// This is exercise 3 of chapter 12 in C++ Primer Plus by Stephen Prata

#ifndef STOCK3_H_
#define STOCK3_H_

#include<iostream>
using std::ostream;

class Stock
{
private:
    char * company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
    Stock();        // default constructor
    Stock(const char * co, int n = 0, double pr = 0.0);
    Stock(const Stock & s); 	// copy constructor
    ~Stock();       // destructor
    void buy(int num, double price);
    void sell(int num, double price);
    void update(double price);
    friend ostream & operator<<(ostream & os, const Stock & s);
    const Stock & topval(const Stock & s) const;
    Stock & operator=(const Stock & s);
};

#endif
