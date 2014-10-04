// pe3-3.cpp -- converts the latitude in degrees, minutes, and seconds to degrees in decimal format
// This is exercise 3 of chapter 3 in C++ Primer Plus by Stephen Prata

#include<iostream>

int main(void)
{
	using namespace std;
	const double Minutes_to_degree = 1/60.0;
	const double Seconds_to_degree = 1/3600.0;
	
	cout << "Enter a latitude in degrees, minutes, and seconds:" << endl;
	cout << "First, enter the degrees: ";
	int degrees;
	cin >> degrees;
	cout << "Next, enter the minutes of the arc: ";
	int minutes;
	cin >> minutes;
	cout << "Finally, enter the seconds of the arc: ";
	int seconds;
	cin >> seconds;
	cout << degrees << " degrees, " << minutes << " minutes, " << seconds << " seconds = ";
	cout << degrees + minutes*Minutes_to_degree + seconds*Seconds_to_degree << " degrees" << endl;
	return 0;
}
