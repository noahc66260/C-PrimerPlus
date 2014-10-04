// pe15-1.cpp -- uses the modified tv.h class
// This is exercise 1 of chapter 15 in C++ Primer Plus 5e by Stephen Prata

#include"tv.h"
#include<iostream>

int main(void)
{
	using namespace std;
	Tv tv;
	Remote remote;

	tv.onoff();
	cout << "Here are our original settings: " << endl;
	tv.settings();
	remote.settings();

	tv.toggleRemoteMode(remote);
	cout << "These are our new settings:" << endl;
	tv.settings();
	remote.settings();

	cout << "Bye!" << endl;

	return 0;
}	
