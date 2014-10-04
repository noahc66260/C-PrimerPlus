// pe5-8.cpp -- this is version 2 of count_words which instead uses the string class instead of a char array. 
// This is exercise 8 of chapter 5 in C++ Primer Plus by Stephen Prata

#include<iostream>
#include<string>

int main(void)
{
	using namespace std;
	string delimiter = "done";
	string word;
	int word_count = 0;

	cout << "Enter words (to stop, type the word done): ";
	cin >> word;

	// while loop to read each word. test condition checks if "done" is entered	
	while (word != delimiter)
	{
		word_count++;
		cin >> word;
	}

	cout << "You entered a total of " << word_count << " words" << endl;	
	
	return 0;
}


