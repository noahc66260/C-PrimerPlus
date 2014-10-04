// pe16-5.cpp -- description here
// This is exercise 5 of chapter 16 in C++ Primer Plus 5e by Stephen Prata

#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<cstdlib>

const int SIZE = 15;
using namespace std;

template <class T>
int reduce(T ar[], int n);
template <>
int reduce<string>(string ar[], int n);

template <class T>
int data_input(T ar[], int n);
template <>
int data_input<string>(string ar[], int n);

template <class T>
void display(T ar[], int begin, int end);

bool string_compare(string s1, string s2);

int main(void)
{
	cout << "Would you like to enter strings or integers? "
		<< "(s for strings, i for integers)" << endl;
	char ch;
	ch = cin.get();
	ch = tolower(ch);
	if (ch != 's' && ch != 'i')
	{
		cout << "Input should be \"s\" or \"i\" (case insensitive)";
		cout << endl;
		cout << "Program abort" << endl;
		exit(EXIT_FAILURE);
	}

	if (ch == 's')
	{
		string sar[SIZE];
		int values = data_input(sar, SIZE);

		if (0 == values)
		{
			cout << "No values were entered" << endl;
			return 0;
		}

		cout << "You entered ";
		display(sar, 0, values);

		cout << "Here's your sorted array, without duplicates: \n";
		int j = reduce(sar, values);
		display(sar, 0, j);
	}
	else
	{
		long ar[SIZE];
		int values = data_input(ar, SIZE);

		if (0 == values)
		{
			cout << "No values were entered" << endl;
			return 0;
		}

		cout << "You entered ";
		display(ar, 0, values);

		cout << "Here's your sorted array, without duplicates: \n";
		int j = reduce(ar, values);
		display(ar, 0, j);
	}

	return 0;
}

template <class T>
int reduce(T ar[], int n)
{
	vector<T> var;
	for (int i = 0; i < n; i++)
		var.push_back(ar[i]);

	sort(var.begin(), var.end());
	typename vector<T>::iterator end = unique(var.begin(), var.end());
	var.erase(end, var.end());
	typename vector<T>::iterator iv = var.begin();
	for (int i = 0; iv != var.end(); iv++, i++)
		ar[i] = *iv;
	
	return var.size();
}

template <>
int reduce<string>(string ar[], int n)
{
	vector<string> var;
	for (int i = 0; i < n; i++)
		var.push_back(ar[i]);

	sort(var.begin(), var.end(), string_compare);
	vector<string>::iterator end 
		= unique(var.begin(), var.end());
	var.erase(end, var.end());
	vector<string>::iterator iv = var.begin();
	for (int i = 0; iv != var.end(); iv++, i++)
		ar[i] = *iv;
	
	return var.size();
}

template <class T>
int data_input(T ar[], int n)
{
	cout << "Enter up to " << n << " values (quit to quit):";
	T value;
	int i = 0;
	while (cin >> value && i < n )
		ar[i++] = value;
	return i;
}

template <>
int data_input<string>(string ar[], int n)
{
	cout << "Enter up to " << n << " strings (quit to quit):";
	string value;
	int i = 0;
	while (cin >> value && i < n && value != "quit" )
		ar[i++] = value;
	return i;
}

template <class T>
void display(T ar[], int begin, int end)
{
	for (int k = begin; k < end; k++)
		cout << ar[k] << " ";
	cout << endl;
}

bool string_compare(string s1, string s2)
{
	transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
	return s1 < s2;
}
