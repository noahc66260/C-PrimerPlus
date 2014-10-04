// stonewt2.h -- modified version of stonewt.h
// This is exercise 5 of chapter 11 in C++ Primer Plus by Stephen Prata
// see stonewt2.h or listing 11.16 in C++ Primer Plus for the original

#ifndef STONEWT2_H_
#define STONEWT2_H_
class Stonewt
{
	/*
		Class invariants:
			state == '1' || state == '2' || state == '3'
	*/

private:
	enum {Lbs_per_stn = 14};	// pounds per stone
	int stone;					// whole stones
	double pds_left;			// fractional pounds
	double pounds;				// entire weight in pounds
	char state;
		// '1' corresponds to stone form
		// '2' corresponds to int pound form
		// '3' corresponds to floating pound form
public:
	Stonewt(double lbs, char st = '1');		// constructor for double pounds
	Stonewt(int stn, double lbs, char st = '1'); 	
	Stonewt(); 					// default constructor
	~Stonewt();
	void set_state(char st);
	friend Stonewt operator+(const Stonewt & s1, const Stonewt & s2);
	friend Stonewt operator-(const Stonewt & s1, const Stonewt & s2);
	friend Stonewt operator*(const Stonewt & s, double d);
	friend Stonewt operator*(double d, const Stonewt & s);
	friend std::ostream & operator<<(std::ostream & os, 
		const Stonewt & s);
};
#endif



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
