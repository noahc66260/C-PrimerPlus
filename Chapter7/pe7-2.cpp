// pe7-2.cpp -- reports the average of up to 10 golf scores
// This is exercise 2 of chapter 7 in C++ Primer Plus by Stephen Prata

#include<iostream>

const int MAX = 10; // the maximum number of entries allowed

// input
int inputScores(int scores[], int max);

// display
void displayScores(const int scores[], int numScores);

// calculate average
double averageScore(const int scores[], int numScores);

using namespace std;

int main(void)
{
	int arr[MAX];
	int entries = inputScores(arr, MAX);

	if (entries)
	{	
		displayScores(arr, entries);
		cout << "The average score is " << averageScore(arr, entries) << endl;
	}
	else
		cout << "There are no scores to display or calculate the average for." 
		     << endl << "Bye!" << endl;
	
	return 0;
}

// input
int inputScores(int scores[], int max)
{
	cout << "You may enter up to " << max << " scores" << endl;
	cout << "Enter score #1 (enter \"f\" when finished): ";

	int score;
	int count = 0;
	while (count < max && cin >> score)
	{		
		scores[count++] = score;
		if (count < max)		
			cout << "Enter score #" << count + 1 << " (enter \"f\" when finished): ";		
	}
	return count;
}

// display
void displayScores(const int scores[], int numScores)
{
	cout << "The scores are as follows: ";
	int i = 0;
	while (i < numScores)
		cout << scores[i++] << "  ";
	cout << endl;
	
	return;
}

// calculate average
double averageScore(const int scores[], int numScores)
{
	int sum = 0;
	int i = 0;
	while (i < numScores)
	{
		sum += scores[i++];
	}
	return (double) sum / numScores;
}
