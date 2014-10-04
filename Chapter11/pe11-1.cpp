// pe11-1.cpp -- a modification of listing 11.15
// This is exercise 1 of chapter 11 in C++ Primer Plus by Stephen Prata
// compile with the vect2.cpp file

#include <iostream>
#include<cstdlib>
#include <ctime>
#include "vect2.h"
#include <fstream>
int main()
{
	using namespace std;

	// create ofstream object and open it
	ofstream myfile;
	myfile.open("q1_log.txt");
	

	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;

		// print output to file
		myfile << steps << ": " << result << endl;

		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.set(dstep, direction, 'p');
			result = result + step;
			steps++;

			// print output to file
			myfile << steps << ": " << result << endl;
		}
		myfile << "After " << steps << " steps, the subject "
			"has the following location:\n";
		myfile << result << endl;
		result.polar_mode();
		myfile << "or\n" << result << endl;
		myfile << "Average outward distance per step = "
		<< result.magval()/steps << endl;
		steps = 0;
		result.set(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";

	// close file
	myfile.close();

	return 0;
}

// This is the original code for listing 11.15
// randwalk.cpp -- using the Vector class
// compile with the vect.cpp file
//#include <iostream>
//#include<cstdlib>
//#include <ctime>
//#include "vect.h"
//int main()
//{
//	using namespace std;
//	using VECTOR::Vector;
//	srand(time(0));
//	double direction;
//	Vector step;
//	Vector result(0.0, 0.0);
//	unsigned long steps = 0;
//	double target;
//	double dstep;
//	cout << "Enter target distance (q to quit): ";
//	while (cin >> target)
//	{
//		cout << "Enter step length: ";
//		if (!(cin >> dstep))
//			break;
//
//		while (result.magval() < target)
//		{
//			direction = rand() % 360;
//			step.set(dstep, direction, 'p');
//			result = result + step;
//			steps++;
//		}
//		cout << "After " << steps << " steps, the subject "
//			"has the following location:\n";
//		cout << result << endl;
//		result.polar_mode();
//		cout << "or\n" << result << endl;
//		cout << "Average outward distance per step = "
//		<< result.magval()/steps << endl;
//		steps = 0;
//		result.set(0.0, 0.0);
//		cout << "Enter target distance (q to quit): ";
//	}
//	cout << "Bye!\n";
//
//	return 0;
//}
