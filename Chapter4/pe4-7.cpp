// pe4-7.cpp -- the user is asked for information regarding a pizza and the program displays that information.
// This is exercise 7 of chapter 4 in C++ Primer Plus by Stephen Prata

#include<iostream>
struct pizza 
{
	char name[20];
	float diameter;
	float weight;
};

int main(void)
{
	using namespace std; 
	pizza pie;
	
	cout << "What is the name of the pizza company? ";
	cin.getline(pie.name, 20);
	
	cout << "What is the diameter of the pizza? ";
	cin >> pie.diameter;
	
	cout << "What is the weight of the pizza? ";
	cin >> pie.weight;
	
	cout << "The name of the pizza company is " << pie.name << endl
	     << "The diameter is " << pie.diameter << endl
	     << "The weight is " << pie.weight << endl;	
	
	return 0;
}

