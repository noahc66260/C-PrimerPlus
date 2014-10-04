// pe3-4.cpp -- converts seconds to equivalent time in days, hours, minutes, and seconds.
// This is exercise 4 of chapter 3 in C++ Primer Plus by Stephen Prata

#include<iostream>

int main(void)
{
	using namespace std;
	const int Seconds_per_minute = 60;
	const int Seconds_per_hour = 60*60;
	const int Seconds_per_day = 60*60*24;

	cout << "Please enter the number of seconds: ";
	long int total_seconds;
	cin >> total_seconds;
	
	int days, hours, minutes, seconds;
	days = total_seconds / Seconds_per_day;
	hours = (total_seconds % Seconds_per_day) / Seconds_per_hour;
	minutes = (total_seconds % Seconds_per_hour) / Seconds_per_minute;
	seconds = (total_seconds % Seconds_per_minute);

	cout << total_seconds << " seconds = " << days << " days, " << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds." << endl;
	return 0;
}
	
