// pe3-6.cpp -- liters per 100 km gasoline consumption to miles per gallon
// This is exercise 6 of chapter 3 in C++ Primer Plus by Stephen Prata

#include<iostream>

int main(void)
{
	using namespace std;
	const double gallons_per_liter = 1/3.875;
	const double km_per_mile = 100/62.14;

	cout << "Enter the gas consumption in liters per 100 km: ";
	double lp100km;
	cin >> lp100km;
	double mpg = 1/(lp100km / 100 * gallons_per_liter * km_per_mile);
	cout << lp100km << " liters per 100 km is equivalent to " << mpg << " miles per gallon" << endl;
	return 0;
}
