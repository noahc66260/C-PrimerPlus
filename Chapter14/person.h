// person.h -- Interface for Person class and derived classes
// This is exercise 4 of chapter 14 in C++ Primer Plus 5e by Stephen Prata

#ifndef PERSON_H_
#define PERSON_H_

#include<iostream>
using std::string;

class Person
{
private:
	string firstname;
	string lastname;
protected:
	virtual void Data() const;
public:
	Person(const string & first = "", const string & last = "");
	virtual ~Person() {}
	void setFirstName(const string & s) {firstname = s;}
	void setLastName(const string & s) {lastname = s;}
	virtual void Show() const;
	virtual void Set();
};

class Gunslinger : virtual public Person
{
private:
	double drawtime;
	int notches;
protected:
	void Data() const;
	virtual void setData();
public:
	Gunslinger(string first = "", string last = "", double d = 0, 
		int n = 0);
	~Gunslinger() {}
	void setDrawTime(double d);
	void setNotches(int n);
	double Draw() const {return drawtime;}
	int Notches() const {return notches;}
	virtual void Show() const;
	virtual void Set() {Person::Set(); Gunslinger::setData();}
};

class PokerPlayer : virtual public Person
{
public:
	PokerPlayer(string first = "", string last = "");
	~PokerPlayer() {}
	int Draw() const {return rand()%52;}
	virtual void Show() const;
	virtual void Set() {Person::Set();}
};

class BadDude : public Gunslinger, public PokerPlayer
{
public:
	BadDude(string first = "", string last = "", double d = 0, 
		int n = 0);
	~BadDude() {}
	double Gdraw() const {return Gunslinger::Draw();} // returns draw time
	int Cdraw() const {return PokerPlayer::Draw();} // returns next card drawn
	virtual void Show() const;
	void Set();
};

#endif
