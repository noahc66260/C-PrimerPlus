// mytime4.h -- modified version of mytime3.h
// This is exercise 4 of chapter 11 in C++ Primer Plus by Stephen Prata
// see mytime3.h or listing 11.10 in C++ Primer Plus for the original file

#ifndef MYTIME4_H_
#define MYTIME4_H_
#include<iostream>

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	friend Time operator+(const Time & t1, const Time & t2);
	friend Time operator-(const Time & t1, const Time & t2);
	friend Time operator*(const Time & t, double mult);
	friend Time operator*(double mult, const Time & t)
		{return t * mult;}
	friend std::ostream & operator<<(std::ostream & os, const Time & t);
};
#endif


// This is listing 11.10
// mytime3.h -- Time class with friends
//#ifndef MYTIME3_H_
//#define MYTIME3_H_
//#include<iostream>
//
//class Time
//{
//private:
//	int hours;
//	int minutes;
//public:
//	Time();
//	Time(int h, int m = 0);
//	void AddMin(int m);
//	void AddHr(int h);
//	void Reset(int h = 0, int m = 0);
//	Time operator+(const Time & t) const;
//	Time operator-(const Time & t) const;
//	Time operator*(double n) const;
//	friend Time operator*(double m, const Time & t)
//		{ return t * m; }
//	friend std::ostream & operator<<(std::ostream & os, const Time & t);
//};
//#endif
