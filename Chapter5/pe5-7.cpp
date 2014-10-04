// pe5-7.cpp -- the program counts words in the input until the word done is entered. The word count does not include the delimiter "done"
// This is exercise 7 of chapter 5 in C++ Primer Plus by Stephen Prata

#include<iostream>
#include<cstring>

int main(void)
{
	using namespace std;
	char delimiter[] = "done";
	const int max_length = 50;
	char word[max_length];
	int word_count = 0;

	cout << "Enter words (to stop, type the word done): ";
	cin >> word;

	// while loop to read each word. test condition checks if "done" is entered	
	while (strcmp(word, delimiter))
	{
		word_count++;
		cin >> word;
	}

	cout << "You entered a total of " << word_count << " words" << endl;	
	
	return 0;
}


