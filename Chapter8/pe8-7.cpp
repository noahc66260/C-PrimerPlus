// pe8-7.cpp -- a modified version of listing 8.14 in Stephen Prata's
// C++ Primer Plus. The template functions are now to return the
// sum of the array contents instead of displaying them. Also the program
// will report the total number of things and the sum of the debts.
// This is exercise 7 of chapter 8 in C++ Primer Plus by Stephen Prata

#include<iostream>

template <typename T>		// template A
T SumArray(T arr[], int n);

template <typename T> 		// template B
T SumArray(T * arr[], int n);

struct debts
{
	char name[50];
	double amount;
};

int main(void)
{
	using namespace std;
	int things[6] = {13, 31, 103, 301, 310, 130};
	struct debts mr_E[3] = 
	{
		{"Ima Wolfe", 2400.0},
		{"Ura Foxe ", 1300.0},
		{"Iby Stout", 1800.0}
	};
	double * pd[3];

// set pointers to the amount members of the structures in the arr mr_E
	for (int i = 0; i < 3; i++)
		pd[i] = &mr_E[i].amount;

	cout << "Total number of Mr. E's things:\n";
// things is an array of int
	cout << SumArray(things, 6) << endl;	// uses template A
	cout << "Total sum of Mr. E's debts: \n";
// pd is an array of pointers to double
	cout << SumArray(pd, 3);  // uses template B (more specialized)
	cout << endl;
	return 0;
}

template <typename T>
T SumArray(T arr[], int n)
{
	T sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	return sum;
}

template <typename T>
T SumArray(T * arr[], int n)
{
	T sum = 0;
	for (int i = 0; i < n; i++)
		sum += *arr[i];
	return sum;
}

// Here is the original listing 8.14

//#include<iostream>
//
//template <typename T>		// template A
//void SumArray(T arr[], int n);
//
//template <typename T> 		// template B
//void SumArray(T * arr[], int n);
//
//struct debts
//{
//	char name[50];
//	double amount;
//};
//
//int main(void)
//{
//	using namespace std;
//	int things[6] = {13, 31, 103, 301, 310, 130};
//	struct debts mr_E[3] = 
//	{
//		{"Ima Wolfe", 2400.0},
//		{"Ura Foxe ", 1300.0},
//		{"Iby Stout", 1800.0}
//	};
//	double * pd[3];
//
//// set pointers to the amount members of the structures in the arr mr_E
//	for (int i = 0; i < 3; i++)
//		pd[i] = &mr_E[i].amount;
//
//	cout << "Listing Mr. E's counts of things:\n";
//// things is an array of int
//	SumArray(things, 6);	// uses template A
//	cout << "Listing Mr. E's debts: \n";
//// pd is an array of pointers to double
//	SumArray(pd, 3); 	// uses template B (more specialized)
//	return 0;
//}
//
//template <typename T>
//void SumArray(T arr[], int n)
//{
//	using namespace std;
//	cout << "template A\n";
//	for (int i = 0; i < n; i++)
//		cout << arr[i] << ' ';
//	cout << endl;
//}
//
//template <typename T>
//void SumArray(T * arr[], int n)
//{
//	using namespace std;
//	cout << "template B\n";
//	for (int i = 0; i < n; i++)
//		cout << *arr[i] << ' ';
//	cout << endl;
//}
