// pe16-2.cpp -- description here
// This is exercise 2 of chapter 16 in C++ Primer Plus 5e by Stephen Prata

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

	string palindrome;
	for (unsigned int i = 0; i < s.size(); i++)
		if (isalpha(s[i]))
			palindrome.push_back(tolower(s[i]));

	for (int i = 0, j = palindrome.size()-1; i < j; i++, j--)
		if (palindrome[i] != palindrome[j])
			return false;

	return true;
}
