// pe8-1.cpp -- main() uses a function with two arguments that displays a string either once or the number of times that the function was called.
// This is exercise 1 of chapter 8 in C++ Primer Plus by Stephen Prata

#include<iostream>

const int MAXLEN = 100; 	// the size of our char array for holding input

void repeatString(const char * str, int echo = 0);

int main(void)
{
	using namespace std; 
	
	cout << "Enter some characters: ";
	char str[MAXLEN];
	cin.getline(str, MAXLEN);

	cout << "repeatString(str)    = ";
	repeatString(str);
	cout << "repeatString(str, 1) = ";
	repeatString(str, 1);
	cout << "repeatString(str)    = ";
	repeatString(str);
	cout << "repeatString(str, 1) = ";
	repeatString(str, 1);
	
	return 0;
}

// prints the string pointed to by str the number of times the function has been called if echo is non-zero, prints once otherwise
void repeatString(const char * str, int echo)
{
	using namespace std;
	static int count = 0; 	// we use count to keep track of the number of function calls
	count++;

	if (echo == 0) 
	{
		cout << str << endl;
		return;
	} 

	else 
	{
		for (int i = 0; i < count; i++)
			cout << str << ' ';
	}
	
	cout << endl;
	return;
}
