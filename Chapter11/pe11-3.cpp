// pe11-3.cpp -- a modification of listing 11.15
// This is exercise 3 of chapter 11 in C++ Primer Plus by Stephen Prata
// compile with the vect2.cpp

#include <iostream>
#include<cstdlib>
#include <ctime>
#include "vect2.h"
#include <fstream>
int main()
{
	using namespace std;

	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	unsigned long trials, highest, lowest, sum;
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		// have user enter number of trials
		cout << "Enter number of trials: ";
		if (!(cin >> trials))
			break;	
	
		// for loop to loop over the number of trials
		sum = 0;
		for (unsigned long i = 0; i < trials; i++)
		{	
			while (result.magval() < target)
			{
				direction = rand() % 360;
				step.set(dstep, direction, 'p');
				result = result + step;
				steps++;
			}

			if (0 == i)
				highest = lowest = steps;
			
			if (steps > highest)
				highest = steps;
			else if (steps < lowest)
				lowest = steps;

			sum += steps;
			steps = 0;
			result.set(0.0, 0.0);
		}

		// print results
		cout << "After " << trials << " trials:" << endl;
		cout << "The average number of steps was "
			<< sum/trials << endl;
		cout << "The lowest number of steps was " 
			<< lowest << endl;
		cout << "The highest number of steps was " 
			<< highest << endl;
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";

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
