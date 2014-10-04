// pe4-1.cpp -- this program requests and displays information
// This is exercise 1 of chapter 4 in C++ Primer Plus by Stephen Prata

#include<iostream>

int main(void)
{
	using namespace std; 
	cout << "What is your first name? ";
	char first_name[20];
	cin.getline(first_name, 20); // we can see that cin does not leave a new line character after reading text
	first_name[19] = '\0';
	//cin.get();  // This is unnecessary because the member function getline() does not leave a newline character in the input
	cout << "What is your last name? ";
	char last_name[20];
	cin.getline(last_name, 20);
	last_name[19] = '\0';
	cout << "What letter grade do you deserve? ";
	char grade;
	cin >> grade;
	cout << "What is your age? ";
	int age;
	cin >> age;
	
	cout << "Name: " << last_name << ", " << first_name << endl
	     << "Grade: " << char (grade + 1) << endl
	     << "Age: " << age << endl;
	return 0;
}
