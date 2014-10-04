// pe8-3.cpp -- echos a string in upper case characters
// This is exercise 3 of chapter 8 in C++ Primer Plus by Stephen Prata

#include<iostream>
#include<string>

using namespace std;

// function takes string reference and converts the contents to uppercase
void stringToUpper(string & str);

int main(void)
{
	cout << "Enter a string (q to quit): "; 
	string str;
	getline(cin, str);

	while (str != "q")
	{
		stringToUpper(str);
		cout << str << endl;
		cout << "Enter a string (q to quit): "; 
		getline(cin, str);
	}
	return 0;
}

void stringToUpper(string & str)
{
	for (int i = 0; i < str.size(); i++)
		str[i] = toupper(str[i]);
}
