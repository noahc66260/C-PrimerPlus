// pe11-4.cpp -- modified version of mytime3.h
// This is exercise 4 of chapter 11 in C++ Primer Plus by Stephen Prata
// see mytime3.cpp or listing 11.11 in C++ Primer Plus for the original file

#include "mytime4.h"

Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::AddHr(int h)
{
	hours += h;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

Time operator+(const Time & t1, const Time & t2)
{
	Time sum;
	sum.minutes = t1.minutes + t2.minutes; 
	sum.hours = t1.hours + t2.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

Time operator-(const Time & t1, const Time & t2)
{
	Time diff;
	int tot1, tot2;
	tot1 = t1.minutes + 60 * t1.hours;
	tot2 = t2.minutes + 60 * t2.hours;
	diff.minutes = (tot2 - tot1) % 60;
	diff.hours = (tot2 - tot1) / 60;
	return diff;
}

Time operator*(const Time & t, double mult)
{
	Time result; 
	long totalminutes = t.hours * mult * 60 + t.minutes * mult;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

std::ostream & operator<<(std::ostream & os, const Time & t)
{
	os << t.hours << " hours, " << t.minutes << " minutes";
	return os;
}



// This is listing 11.11
// mytime3.cpp -- implementing Time methods
//#include "mytime3.h"
//
//Time::Time()
//{
//	hours = minutes = 0;
//}
//
//Time::Time(int h, int m)
//{
//	hours = h;
//	minutes = m;
//}
//
//void Time::AddMin(int m)
//{
//	minutes += m;
//	hours += minutes / 60;
//	minutes %= 60;
//}
//
//void Time::AddHr(int h)
//{
//	hours += h;
//}
//
//void Time::Reset(int h, int m)
//{
//	hours = h;
//	minutes = m;
//}
//
//Time Time::operator+(const Time & t) const
//{
//	Time sum;
//	sum.minutes = minutes + t.minutes; 
//	sum.hours = hours + t.hours + sum.minutes / 60;
//	sum.minutes %= 60;
//	return sum;
//}
//
//Time Time::operator-(const Time & t) const
//{
//	Time diff;
//	int tot1, tot2;
//	tot1 = t.minutes + 60 * t.hours;
//	tot2 = minutes + 60 * hours;
//	diff.minutes = (tot2 - tot1) % 60;
//	diff.hours = (tot2 - tot1) / 60;
//	return diff;
//}
//
//Time Time::operator*(double mult) const
//{
//	Time result; 
//	long totalminutes = hours * mult * 60 + minutes * mult;
//	result.hours = totalminutes / 60;
//	result.minutes = totalminutes % 60;
//	return result;
//}
//
//std::ostream & operator<<(std::ostream & os, const Time & t)
//{
//	os << t.hours << " hours, " << t.minutes << " minutes";
//	return os;
//}
