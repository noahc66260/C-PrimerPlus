// pe3-2.cpp -- calculates user's bmi
// This is exercise 2 of chapter 3 in C++ Primer Plus by Stephen Prata

#include<iostream>

int main(void)
{
	using namespace std;
	const int Feet_to_inches = 12;
	const double Inches_to_meter = 0.0254;
	const double Pounds_to_kg = 1/2.2;

	cout << "Please enter your height in feet and inches." << endl;
	cout << "Feet: ";
	int feet_tall;
	cin >> feet_tall;
	cout << "Inches: ";
	int inches_tall;
	cin >> inches_tall;
	cout << "What is your weight in pounds? ";
	int pounds;
	cin >> pounds;

	double height_meters = (feet_tall*Feet_to_inches + inches_tall)*Inches_to_meter;
	double weight_kg = pounds*Pounds_to_kg;

	cout << "Your BMI is " << weight_kg / (height_meters * height_meters) << endl;
	return 0;
}
