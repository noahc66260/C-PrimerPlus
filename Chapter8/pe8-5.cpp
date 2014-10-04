// pe8-5.cpp -- uses a template function to find the largest
// value in an array of size 5 and returns that value.
// This is exercise 5 of chapter 8 in C++ Primer Plus by Stephen Prata

#include<iostream>

template <typename T>
T max5(T arr[]);

int main(void)
{
	using namespace std;

	cout << "Enter five int values (s to skip): ";
	int i1, i2, i3, i4, i5;
	if (cin >> i1 >> i2 >> i3 >> i4 >> i5)
	{
		int arri[5] = {i1, i2, i3, i4, i5};
		int maxi = max5(arri);
		cout << "The maximum value is " << maxi << endl;
	}

	cout << "Enter five double values (s to skip): ";
	double d1, d2, d3, d4, d5;
	cin.ignore(100, '\n');	// discard any input in buffer
	if (cin >> d1 >> d2 >> d3 >> d4 >> d5)
	{
		double arrd[5] = {d1, d2, d3, d4, d5};
		double maxd = max5(arrd);
		cout << "The maximum value is " << maxd << endl;
	}
	
	cout << "Bye!" << endl;

	return 0;
}

// returns the maximum value in the array
template <typename T>
T max5(T arr[])
{
	T max = arr[0];
	for (int i = 1; i < 5; i++)
	{
		if (arr[i] > max)
			max = arr[i]; 
	}
	return max;
}
