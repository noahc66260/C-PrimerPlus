// pe17-1.cpp -- description here
// This is exercise 1 of chapter 17 in C++ Primer Plus 5e by Stephen Prata

#include<iostream>

int main(void)
{
	using namespace std;
	cout << "Enter whatever you'd like." << endl;
	cout << "Input will be read up until the first '$' character:" << endl;
	char ch;
	cin.get(ch);
	int count = 0;
	
	while (ch != '$')
	{
		count++;
		cin.get(ch);
	}
	cin.putback(ch);
	cout << count << " characters read." << endl;
	cout << "The next character in the input buffer is " 
		<< (char) cin.get() << endl;
	cin.putback(ch);

	return 0;
}
