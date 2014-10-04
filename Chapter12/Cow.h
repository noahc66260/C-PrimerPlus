// Cow.h -- interface of the Cow class (code given by book)
// This is exercise 1 of chapter 12 in C++ Primer Plus by Stephen Prata
// this code is accompanied by Cow.cpp and questionOne.cpp

class Cow
{
	char name[20];
	char * hobby;
	double weight;
public:
	Cow();
	Cow(const char * nm, const char * ho, double wt);
	Cow(const Cow & c);
	~Cow();
	Cow & operator=(const Cow & c);
	void ShowCow() const; 	// display all cow data
};
