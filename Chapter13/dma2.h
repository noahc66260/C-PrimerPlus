// dma2.h -- uses an ABC for baseDMA, hasDMA, lacksDMA class methods
// This is exercise 3 of chapter 12 in C++ Primer Plus by Stephen Prata


#ifndef DMA2_H_
#define DMA2_H_
#include <iostream>

// Abstract base class
class abcDMA
{
private:
	char * label;
	int rating;
protected:
	const char * showLabel() const {return label;}
	int showRating() const {return rating;}
public:
	abcDMA(const char * l = "NULL", int r = 0);
	abcDMA(const abcDMA & a);
	virtual void View() const = 0; // pure virtual function
	virtual ~abcDMA();
	abcDMA & operator=(const abcDMA & a);
	friend std::ostream & operator<<(std::ostream & os, 
		const abcDMA & rs);
};

//  Base Class Using DMA
class baseDMA : public abcDMA
{
private:
public:
    baseDMA(const char * l = "null", int r = 0);
    baseDMA(const baseDMA & rs);
    virtual ~baseDMA();
    baseDMA & operator=(const baseDMA & rs);
	virtual void View() const;
	friend std::ostream & operator<<(std::ostream & os, 
		const baseDMA & rs);
};

// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA :public abcDMA
{
private:
    enum { COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char * c = "blank", const char * l = "null",
              int r = 0);
	friend std::ostream & operator<<(std::ostream & os, 
		const lacksDMA & rs);
	virtual void View() const;
};

// derived class with DMA
class hasDMA : public abcDMA
{
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char * l = "null",
              int r = 0);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & rs);
	friend std::ostream & operator<<(std::ostream & os, 
		const hasDMA & rs);
	virtual void View() const;
};

#endif
