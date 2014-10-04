// pe16-4.cpp -- description here
// This is exercise 4 of chapter 16 in C++ Primer Plus 5e by Stephen Prata

#include<iostream>
#include<vector>
#include<algorithm>

const int SIZE = 15;
int reduce(long ar[], int n);

int main(void)
{
	using namespace std;

	cout << "Enter up to " << SIZE << " numbers (quit to quit):";
	long num;
	int i = 0;
	long ar[SIZE];
	while (cin >> num && i < SIZE)
	{
		ar[i++] = num;
	}

	if (0 == i)
	{
		cout << "No values were entered" << endl;
		return 0;
	}

	cout << "You entered ";
	for (int j = 0; j < i; j++)
		cout << ar[j] << " ";
	cout << endl;

	cout << "Here's your sorted array, without duplicates: \n";
	int j = reduce(ar, i);
	for (int k = 0; k < j; k++)
		cout << ar[k] << " ";
	cout << endl;

	return 0;
}

int reduce(long ar[], int n)
{
	using namespace std;

	vector<long> var;
	for (int i = 0; i < n; i++)
		var.push_back(ar[i]);

	sort(var.begin(), var.end());
	vector<long>::iterator end = unique(var.begin(), var.end());
	var.erase(end, var.end());
	vector<long>::iterator iv = var.begin();
	for (int i = 0; iv != var.end(); iv++, i++)
		ar[i] = *iv;
	
	return var.size();
}
