// pe6-1.cpp -- the program echos keyboard input except for digits, converting each upper case character to lower case, and vica versa, up to the @ symbol. 
// This is exercise 1 of chapter 6 in C++ Primer Plus by Stephen Prata

#include<iostream>
#include<cctype>

int main(void)
{
	using namespace std; 	

	cout << "You may begin typing, enter @ to quit" << endl;
	char ch;
	cin.get(ch);
	
	while (cin.good() && ch != '@')
	{
		if (isdigit(ch)) 
		{
			cin.get(ch);
			continue;
		}
		else if (isupper(ch))
			ch = tolower(ch);
		else if (islower(ch))
			ch = toupper(ch);
		
		cout << ch;
		cin.get(ch);
	}

	cout << endl << "All done!" << endl;

	return 0;
}

