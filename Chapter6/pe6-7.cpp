// pe6-7.cpp -- reads input until 'q' is entered and then displays words that begin with vowels, consonants, or neither. 
// This is exercise 7 of chapter 6 in C++ Primer Plus by Stephen Prata

#include<iostream>
#include<string>

int main(void)
{
	using namespace std; 

	// Prompt user to enter input
	cout << "Enter words (q to quit): " << endl;
	
	// get data
	string word;
	cin >> word;

	// while loop, test expression evaluates cin.good() and string[0] != 'q'
	int vowels, consonants, neither;
	vowels = consonants = neither = 0;
	while (cin.good() && word != "q") 
	{
		if (isalpha(word[0]))
		{
			if (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u' || word[0] == 'y')
				vowels++;
			else
				consonants++;
		}
		else
			neither++;

		cin >> word;
	}

	// display words beginning with vowels, consonants, and neither
	cout << vowels << " words beginning with vowels" << endl;
	cout << consonants << " words beginning with consonants" << endl;
	cout << neither << " others" << endl;	

	return 0;
}
