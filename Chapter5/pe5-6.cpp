// pe5-6.cpp -- the program asks the user to input data regarding the make and year of various cars and redisplays the information
// This is exercise 6 of chapter 5 in C++ Primer Plus by Stephen Prata

#include<iostream>
#include<string>

int main(void)
{
	using namespace std;
	struct car 
	{
		string make;
		int year;
	};

	cout << "How many cars do you with to catalog? ";
	int number_cars;
	cin >> number_cars;
	cin.get();
	
	car * collection = new car[number_cars];
	int count = 0;
	while (count < number_cars)
	{
		cout << "Car #" << count + 1 << ": " << endl
		     << "Please enter the make: ";
		getline(cin, collection[count].make);
		cout << "Please enter the year made: ";
		cin >> collection[count].year;
		cin.get();
		count += 1;
	}

	cout << "Here is your collection: " << endl;
	for (count = 0; count < number_cars; count++)
	{
		cout << collection[count].year << " " 
		     << collection[count].make << endl;
	}
	
	return 0;
}
