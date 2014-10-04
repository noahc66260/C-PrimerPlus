// pe5-2.cpp -- program asks the user to enter numbers and sums the cumulative entries. Program terminates when the user enters 0
// This is exercise 2 of chapter 5 in C++ Primer Plus by Stephen Prata

#include<iostream>

int main(void)
{
	using namespace std; 		
	cout << "Enter as many numbers as you'd like. Enter 0 to terminate the program. " << endl;
	int num, sum = 0;
	cin >> num;

	while (num != 0)
	{
		sum += num;
		if (cin.get() == '\n')
			cout << "The sum is currently: " << sum << endl;
		cin >> num;
	}
	
	cout << "The grand total is " << sum << endl;
	return 0;
}

