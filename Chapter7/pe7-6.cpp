// pe7-6.cpp -- uses functions to fill an array, display the contents of an array, and reverse the elements of an array
// This is exercise 6 of chapter 7 in C++ Primer Plus by Stephen Prata

#include<iostream>

using namespace std; 

int Fill_array(double arr[], int size);
void Show_array(const double arr[], int size);
void Reverse_array(double arr[], int size);

const int ARR_SIZE = 10;

int main(void)
{
	double arr[ARR_SIZE];
	int entries = Fill_array(arr, ARR_SIZE);

	// show, reverse, show, reverse all but first/last elements, show
	cout << endl << "Here is the array:" << endl;
	Show_array(arr, entries);
	cout << "Let's reverse the array." << endl;
	Reverse_array(arr, entries);
	cout << "Here is our new array:" << endl;
	Show_array(arr, entries);
	cout << "Let's reverse all except the first and last elements." << endl;
	Reverse_array(arr + 1, entries - 2); 
	cout << "Here is our final array:" << endl;
	Show_array(arr, entries);
	
	return 0;
}

// Don't forget to define any functions that you created

int Fill_array(double arr[], int size)
{
	// Every array item is initially set to 0 so that you don't get any strange numbers from unfilled array values. 
	for (size_t j = 0; j < size; j++)
	{
		arr[j] = 0;
	}
	cout << "You may enter up to " << size << " values." << endl;
	cout << "Enter value number 1 (or type \"q\" when finished): ";
	int count = 0;
	while (count < size && cin >> arr[count])
	{
		if (++count < size)
			cout << "Enter value number " << count + 1 << " (or type \"q\" when finished): ";
	}			
	return count;
}

void Show_array(const double arr[], int size)
{
	cout << endl;
	for (int i = 0; i < size; i++)
		cout << "Element number " << i + 1 << " = " << arr[i] << endl;
	cout << endl;
	return;
}

void Reverse_array(double arr[], int size)
{
	int temp;
	for (int i = 0; i < size / 2; i++)
	{
		temp = arr[i];
		arr[i] = arr[(size - 1) - i];
		arr[(size - 1) - i] = temp;
	}
	return;
}
