// pe8-6.cpp -- uses maxn() to find the largest value in an array.
// Also uses a specialization to find the largest string in an array
// of char *. 
// This is exercise 6 of chapter 8 in C++ Primer Plus by Stephen Prata

#include<iostream>
#include<cstring>

template <typename T>
T maxn(T arr[], int size);

template <>
const char * maxn(const char * arr[], int size);

int main(void)
{
	using namespace std;
	char str1[] = "Hello";
	char str2[] = "Hi";
	char str3[] = "Hey";
	char str4[] = "Greetings!";	// 10 characters
	char str5[] = "Goodbye!!!";	// 10 characters

	char * arrs[5] = 
	{
		str1,
		str2,
		str3,
		str4,
		str5
	};

	int arri[5] = {1, 2, 3, 100, -100};

	// use specialization
	cout << "The largest string is " 
	     << maxn(arrs, 5) << endl;

	// use template
	cout << "The largest number is " 
	     << maxn(arri, 5) << endl;

	return 0;
}

template <typename T>
T maxn(T arr[], int size)
{
	T max = arr[0];
	for(int i = 1; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

template <>
const char * maxn(const char * arr[], int size)
{
	const char * longest = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (strlen(arr[i]) > strlen(longest))
			longest = arr[i];
	}
	
	return longest;
}
















