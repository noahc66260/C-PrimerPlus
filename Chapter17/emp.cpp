// emp.cpp -- implementation file for abstr_emp class and children
// This is exercise 6 of chapter 17 in C++ Primer Plus 5e by Stephen Prata
// Updates were made by to include the writeall() and getall() functions

#include<iostream>
#include"emp.h"
#include<fstream>

// abstr_emp class methods
/*
    std::string fname;
    std::string lname;    
    std::string job;
*/
abstr_emp::abstr_emp() : fname(""), lname(""), job("")
{
}

abstr_emp::abstr_emp(const std::string & fn, const std::string &  ln,
	const std::string &  j) : fname(fn), lname(ln), job(j)
{
}

// labels and shows all data
void abstr_emp::ShowAll() const 
{
	using std::cout;
	using std::endl;
	cout << "First name: " << fname << endl;
	cout << "Last name: " << lname << endl;
	cout << "Job: " << job << endl;
}

// prompts user for values
void abstr_emp::SetAll()        
{
	using std::cout;
	using std::endl;
	using std::cin;

	cout << "Enter first name: ";
	cin >> fname;
	while (cin.get() != '\n')
		continue;
	cout << "Enter last name: ";
	cin >> lname;
	while (cin.get() != '\n')
		continue;
	cout << "Enter the job: ";
	getline(cin, job);
}

// just displays first and last name
std::ostream & operator<<(std::ostream & os, const abstr_emp & e)
{
	os << e.lname << ", " << e.fname;
	return os;
}

abstr_emp::~abstr_emp()
{
}

void abstr_emp::writeall(std::ofstream & ofs) const
{
	using std::endl;
	ofs << "First name: " << fname << endl;
	ofs << "Last name: " << lname << endl;
	ofs << "Job: " << job << endl;
}

void abstr_emp::getall(std::ifstream & ifs)
{
	ifs.ignore(256, ':');
	while(' ' == ifs.peek())
		ifs.get();
	getline(ifs, fname); 
	std::cout << "First name is " << fname << std::endl;

	ifs.ignore(256, ':');
	while(' ' == ifs.peek())
		ifs.get();
	getline(ifs, lname);
	std::cout << "Last name is " << lname << std::endl;

	ifs.ignore(256, ':');
	while(' ' == ifs.peek())
		ifs.get();
	getline(ifs, job);  
	std::cout << "Job is " << job << std::endl;
}

// employee class methods (inherits abstr_emp class publically)
employee::employee() : abstr_emp()
{
}

employee::employee(const std::string & fn, const std::string &  ln,
             const std::string &  j) : abstr_emp(fn, ln, j)
{
}

void employee::ShowAll() const
{
	using std::cout;
	using std::endl;
	cout << "Status: Employee" << endl;
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

void employee::writeall(std::ofstream & ofs) const
{
	using std::endl;
	ofs << abstr_emp::Employee << endl;
	abstr_emp::writeall(ofs);
}

void employee::getall(std::ifstream & ifs)
{
	abstr_emp::getall(ifs);
}

// manager class methods (inherits abstr_emp publically and virtually)
/*
    int inchargeof;        // number of abstr_emps managed
*/
manager::manager() : abstr_emp()
{
	inchargeof = 0;
}

manager::manager(const std::string & fn, const std::string & ln,
	const std::string & j, int ico) : abstr_emp(fn, ln, j)
{
	using std::cout;
	using std::endl;
	inchargeof = ico;
	if (inchargeof < 0)
	{
		cout << "Error, cannot be in charge of negative people." << endl;
		cout << "Setting inchargeof to 0" << endl;
		inchargeof = 0;
	}
}

manager::manager(const abstr_emp & e, int ico) : abstr_emp(e)
{
	using std::cout;
	using std::endl;
	inchargeof = ico;
	if (inchargeof < 0)
	{
		cout << "Error, cannot be in charge of negative people." << endl;
		cout << "Setting inchargeof to 0" << endl;
		inchargeof = 0;
	}
}

manager::manager(const manager & m) : abstr_emp(m)
{
	inchargeof = m.inchargeof;
}

void manager::ShowAll() const
{
	using std::cout;
	using std::endl;
	cout << "Status: Manager" << endl;
	abstr_emp::ShowAll();
	cout << "In charge of " << inchargeof << " people" << endl;
}

void manager::SetAll()
{
	using std::cout;
	using std::cin;
	using std::endl;
	abstr_emp::SetAll();
	cout << "Enter the number of people the manager is in charge of: ";
	cin >> inchargeof;
	if (inchargeof < 0)
	{
		cout << "Error, cannot be in charge of negative people." << endl;
		cout << "Setting inchargeof to 0" << endl;
		inchargeof = 0;
	}
}

void manager::writeall(std::ofstream & ofs) const
{
	using std::endl;
	ofs << abstr_emp::Manager << endl;
	abstr_emp::writeall(ofs);
	ofs << "Number of people managed: " << inchargeof << endl;
}

void manager::getall(std::ifstream & ifs)
{
	abstr_emp::getall(ifs);
	ifs.ignore(256, ':');
	ifs >> inchargeof;
	ifs.get(); // discard newline character
}


// fink class methods (inherits abstr_emp publically and virtually)
/*
    std::string reportsto;        // to whom fink reports
*/
fink::fink() : abstr_emp(), reportsto("")
{
}

fink::fink(const std::string & fn, const std::string & ln,
	const std::string & j, const std::string & rpo) 
	: abstr_emp(fn, ln, j), reportsto(rpo)
{
}

fink::fink(const abstr_emp & e, const std::string & rpo) 
	: abstr_emp(e), reportsto(rpo)
{
}

fink::fink(const fink & e) : abstr_emp(e)
{
	reportsto = e.reportsto;
}

void fink::ShowAll() const
{
	using std::cout;
	using std::endl;
	cout << "Status: fink" << endl;
	abstr_emp::ShowAll();
	cout << "Reports to " << reportsto << endl;
}

void fink::SetAll()
{
	using std::cout;
	using std::endl;
	using std::cin;
	abstr_emp::SetAll();
	cout << "Enter whomever is reported to: ";
	getline(cin, reportsto);
}

void fink::writeall(std::ofstream & ofs) const
{
	using std::endl;
	ofs << abstr_emp::Fink << endl;
	abstr_emp::writeall(ofs);
	ofs << "Reports to: " << reportsto << endl;
}

void fink::getall(std::ifstream & ifs)
{
	abstr_emp::getall(ifs);
	ifs.ignore(256, ':');
	getline(ifs, reportsto);
}

// highfink class methods (inherits manager and fink classes publically)
highfink::highfink() : abstr_emp(), manager(), fink()
{
}

highfink::highfink(const std::string & fn, const std::string & ln,
	const std::string & j, const std::string & rpo, int ico) 
	: abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{
}

highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico)
	: abstr_emp(e), manager(e, ico), fink(e, rpo)
{
}

highfink::highfink(const fink & f, int ico)
	: abstr_emp(f), manager(f, ico), fink()
{
}

highfink::highfink(const manager & m, const std::string & rpo)
	: abstr_emp(m), manager(m), fink(m, rpo)
{
}

highfink::highfink(const highfink & h) : abstr_emp(h), manager(h), fink(h)
{
}

void highfink::ShowAll() const
{
	using std::cout;
	using std::endl;
	cout << "Status: Highfink" << endl;
	abstr_emp::ShowAll();
	cout << "In charge of " << InChargeOf() << " people" << endl;
	cout << "Reports to " << ReportsTo() << endl;
}

void highfink::SetAll()
{
	using std::cout;
	using std::endl;
	using std::cin;
	abstr_emp::SetAll();
	cout << "Enter the number of people managed: ";
	cin >> InChargeOf();
	if (InChargeOf() < 0)
	{
		cout << "Error, cannot be in charge of negative people." << endl;
		cout << "Setting inchargeof to 0" << endl;
		InChargeOf() = 0;
	}
	cin.get(); 	// remove newline character
	cout << "Enter whomever is reported to: ";
	getline(cin, ReportsTo());
}

void highfink::writeall(std::ofstream & ofs) const
{
	using std::endl;
	ofs << abstr_emp::Highfink << endl;
	abstr_emp::writeall(ofs);
	ofs << "Number of people managed: " << InChargeOf() << endl;
	ofs << "Reports to: " << ReportsTo() << endl;
}

void highfink::getall(std::ifstream & ifs)
{
	abstr_emp::getall(ifs);
	ifs.ignore(256, ':');
	ifs >> InChargeOf();
	ifs.get(); // discard newline character
	ifs.ignore(256, ':');
	getline(ifs, ReportsTo());
}


















