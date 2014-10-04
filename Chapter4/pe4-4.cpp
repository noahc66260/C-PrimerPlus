// pe4-4.cpp -- asks for the user's name and displays it using the string class
// This is exercise 4 of chapter 4 in C++ Primer Plus by Stephen Prata

#include<iostream>
#include<string>

int main(void)
{
	using namespace std;
	cout << "Enter your first name: ";
	string first_name;
	getline(cin, first_name);
	cout << "Enter your last name: ";
	string last_name;
	getline(cin, last_name);
	string full_name = (last_name + ", ") + first_name;
	cout << "Here's the information on a single string: " 
	     << full_name 
	     << endl;
	return 0;
}


