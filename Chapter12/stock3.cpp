// stock3.cpp - implementation of Stock class
// Note: this is a modified version of listing 10.8
// This is exercise 3 of chapter 12 in C++ Primer Plus by Stephen Prata
// compile with pe12_3.cpp

#include <iostream>
#include "stock3.h"
#include <cstring>

// constructors
Stock::Stock()        // default constructor
{
    using std::strlen;
    using std::strcpy;
    
    company = new char[strlen("no name") + 1];
    strcpy(company, "no name");
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char * co, int n, double pr)
{
	using std::strlen;
	using std::strcpy;

	int len = strlen(co);
	company = new char[len + 1];
    strcpy(company, co); 

    if (n < 0)
    {
        std::cerr << "Number of shares can't be negative; "
                   << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

Stock::Stock(const Stock & s) 	// copy constructor
{
    using std::strlen;
    using std::strcpy;

    int len = strlen(s.company);
    company = new char[len + 1];
    strcpy(company, s.company);
    shares = s.shares;
    share_val = s.share_val;
    total_val = s.total_val;
}

// class destructor
Stock::~Stock()        // quiet class destructor
{
	delete [] company;
}

// other methods
void Stock::buy(int num, double price)
{
     if (num < 0)
    {
        std::cerr << "Number of shares purchased can't be negative. "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(int num, double price)
{
    using std::cerr;
    if (num < 0)
    {
        cerr << "Number of shares sold can't be negative. "
             << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        cerr << "You can't sell more than you have! "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

std::ostream & operator<<(std::ostream & os, const Stock & s)
{
    using std::endl;
    os  << "Company: " << s.company
        << "  Shares: " << s.shares << endl
        << "  Share Price: $" << s.share_val
        << "  Total Worth: $" << s.total_val << endl; 
    return os;
}

const Stock & Stock::topval(const Stock & s) const
{
    if (s.total_val > total_val)
        return s;
    else
        return *this; 
}

Stock & Stock::operator=(const Stock & s)
{
    using std::strlen;
    using std::strcpy;

    if (this == &s)
        return *this;

    int len = strlen(s.company);
    delete [] company;
    company = new char[len + 1];
    strcpy(company, s.company);
    shares = s.shares;
    share_val = s.share_val;
    total_val = s.total_val;    
    return *this;
}

