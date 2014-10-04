// pe16-1.cpp -- description here
// This is exercise 1 of chapter 16 in C++ Primer Plus 5e by Stephen Prata

#include<iostream>

bool isPalindrome(std::string & s);
int main(void)
{
	using namespace std;
	cout << "Enter a string: ";
	string s;
	getline(cin, s);

	if (isPalindrome(s))
		cout << s << " is a palindrome" << endl;
	else
		cout << s << " is not a palindrome" << endl;

	return 0;
}

bool isPalindrome(std::string & s)
{
	using namespace std;

	for (int i = 0, j = s.size()-1; i < j; i++, j--)
		if (s[i] != s[j])
			return false;

	return true;
}
