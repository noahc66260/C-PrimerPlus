// stonewt3.h -- modified version of stonewt.h
// This is exercise 6 of chapter 11 in C++ Primer Plus by Stephen Prata
// see stonewt3.h or listing 11.16 in C++ Primer Plus for the original

#ifndef STONEWT3_H_
#define STONEWT3_H_
class Stonewt
{
private:
	enum {Lbs_per_stn = 14};	// pounds per stone
	int stone;					// whole stones
	double pds_left;			// fractional pounds
	double pounds;				// entire weight in pounds
public:
	Stonewt(double lbs);		// constructor for double pounds
	Stonewt(int stn, double lbs); 	// constructor for stone, lbs
	Stonewt(); 					// default constructor
	~Stonewt();
	void show_lbs() const;	
	void show_stn() const;
	friend bool operator==(const Stonewt & s1, const Stonewt & s2);
	friend bool operator!=(const Stonewt & s1, const Stonewt & s2);	
	friend bool operator>=(const Stonewt & s1, const Stonewt & s2);
	friend bool operator>(const Stonewt & s1, const Stonewt & s2);
	friend bool operator<=(const Stonewt & s1, const Stonewt & s2);
	friend bool operator<(const Stonewt & s1, const Stonewt & s2);
	friend std::ostream & operator<<(std::ostream & os, 
		const Stonewt & s);
};
#endif

// the equality operators are == >= <= > < and !=

// stonewt.h -- definition for the Stonewt class
//
//#ifndef STONEWT_H_
//#define STONEWT_H_
//class Stonewt
//{
//private:
//	enum {Lbs_per_stn = 14};	// pounds per stone
//	int stone;					// whole stones
//	double pds_left;			// fractional pounds
//	double pounds;				// entire weight in pounds
//public:
//	Stonewt(double lbs);		// constructor for double pounds
//	Stonewt(int stn, double lbs); 	// constructor for stone, lbs
//	Stonewt(); 					// default constructor
//	~Stonewt();
//	void show_lbs() const;	
//	void show_stn() const;
//};
//#endif
