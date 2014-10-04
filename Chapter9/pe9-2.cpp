// pe9-2.cpp -- revision of Listing 9.8 (static.cpp) so that it
// uses string objects and not char arrays.
// This is exercise 2 of chapter 9 in C++ Primer Plus by Stephen Prata

#include <iostream>
#include <string> // this library is no longer necessary
using std::string;

// function prototype
void strcount(const string str);

int main()
{
	using namespace std;
	string input;

	cout << "Enter a line:\n";
	getline(cin, input);
	while (input != "")
	{
		strcount(input);
		cout << "Enter next line (empty line to quit):\n";
		getline(cin, input);
	}
	cout << "Bye\n";
	return 0;
}

void strcount(const string str)
{
	using std::cout;
	static int total = 0;
	
	cout << "\"" << str << "\" contains ";
	total += str.size();
	cout << str.size() << " characters\n";
	cout << total << " characters total\n";
	return;
}

// Below is the original listing 9.9
// static.cpp -- using a static local variable
//#include <iostream>
// constants
//const int ArSize = 10;
//
// function prototype
//void strcount(const char * str);
//
//int main()
//{
//	using namespace std;
//	char input[ArSize];
//	char next;
//
//	cout << "Enter a line:\n";
//	cin.get(input, ArSize);
//	while (cin)
//	{
//		cin.get(next);
//		while (next != '\n') 	// string didn't fit!
//			cin.get(next);
//		strcount(input);
//		cout << "Enter next line (empty line to quit):\n";
//		cin.get(input, ArSize);
//	}
//	cout << "Bye\n";
//	return 0;
//}
//
//void strcount(const char * str)
//{
//	using namespace std;
//	static int total = 0;	// static local variable
//	int count = 0;		// automatic local variable
//	
//	cout << "\"" << str << "\" contains ";
//	while (*str++)		// go to end of string
//		count++;
//	total += count;
//	cout << count << " characters\n";
//	cout << total << " characters total\n";
//}
