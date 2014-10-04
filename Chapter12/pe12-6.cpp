// pe12-6.cpp -- finds the maximum number of customers per minute such that
// the average wait time is less than or equal to a minute when there
// are two ATMs
// Note: this program uses code from listing 12.12
// This is exercise 6 of chapter 12 in C++ Primer Plus by Stephen Prata
// compile with queue.cpp

#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include "queue.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x); // is there a new customer?

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;
	std::srand(std::time(0));    //  random initializing of rand()

	int hours = 100; 	// hours in simulation
	// simulation will run 1 cycle per minute
	long cyclelimit = MIN_PER_HR * hours; // # of cycles

	double perhour;         //  average # of arrival per hour
	double min_per_cust;    //  average time between arrivals
	Item temp;              //  new customer data

	long turnawaysL1;
	long customersL1;     //  joined the queue
	long servedL1;        //  served during the simulation
	long sum_lineL1;      //  cumulative line length
	int wait_timeL1;      //  time until autoteller is free
	long line_waitL1;     //  cumulative time in line

	long turnawaysL2;
	long customersL2;     //  joined the queue
	long servedL2;        //  served during the simulation
	long sum_lineL2;      //  cumulative line length
	int wait_timeL2;      //  time until autoteller is free
	long line_waitL2;     //  cumulative time in line

	double average_wait; 	// average wait time
	int i = 120; 	// we know that with 120 people per hour
						// the average wait time will be longer
						// than 1 minute per person at two ATMs
	do
	{
		perhour = i--;	// we will update i for each loop
		Queue line1(hours * perhour / 2);
		Queue line2(hours * perhour / 2);
			// we set our queue size to the total number of 
			// customers we expect to see in our simulation
			// so that none of them are turned away.
		min_per_cust = MIN_PER_HR / perhour;
		turnawaysL1 = turnawaysL2 = 0;		// turned away
		customersL1 = customersL2 = 0;     //  joined the queue
		servedL1 = servedL2 = 0;        //  served during the simulation
		sum_lineL1 = sum_lineL2 = 0;      //  cumulative line length
		wait_timeL1 = wait_timeL2 = 0;      //  time until autoteller is free
		line_waitL1 = line_waitL2 = 0;     //  cumulative time in line

	// running the simulation
		for (int cycle = 0; cycle < cyclelimit; cycle++)
		{
			// if we have a newcomer, we put them
			// in the smaller queue
			if (newcustomer(min_per_cust))  // have newcomer
			{
				if (line1.queuecount() <= line2.queuecount())
				{
					if (line1.isfull())
						turnawaysL1++;
					else
					{
						customersL1++;
						temp.set(cycle);    // cycle = time of arrival
						line1.enqueue(temp); // add newcomer to line
					}
				}
				else
				{
					if (line2.isfull())
						turnawaysL2++;
					else
					{
						customersL2++;
						temp.set(cycle);    // cycle = time of arrival
						line2.enqueue(temp); // add newcomer to line
					}
				}
			}
			if (wait_timeL1 == 0 && !line1.isempty())
			{
				line1.dequeue (temp);      // attend next customer
				wait_timeL1 = temp.ptime(); // for wait_time minutes
				line_waitL1 += cycle - temp.when();
				servedL1++;
			}
			if (wait_timeL2 == 0 && !line2.isempty())
			{
				line2.dequeue (temp);      // attend next customer
				wait_timeL2 = temp.ptime(); // for wait_time minutes
				line_waitL2 += cycle - temp.when();
				servedL2++;
			}
			if (wait_timeL1 > 0)
				wait_timeL1--;
			if (wait_timeL2 > 0)
				wait_timeL2--;
			sum_lineL1 += line1.queuecount();
			sum_lineL2 += line2.queuecount();
		}
		line1.~Queue();
		line2.~Queue();
		average_wait = double (line_waitL1 + line_waitL2) /
								(servedL1 + servedL2);
	}
	while (average_wait > 1.0);
	i++; // account for decrement of i on last loop

// reporting results
	if (customersL1 + customersL2 > 0)
	{
		cout << "customers per hour: " << i << endl;
		cout << "customers accepted: " << customersL1 + customersL2 << endl;
		cout << "  customers served: " << servedL1 + servedL2 << endl;
		cout << "         turnaways: " << turnawaysL1 + turnawaysL2 << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.setf(ios_base::showpoint);
		cout << (double) (sum_lineL1*sum_lineL1 + sum_lineL2*sum_lineL2) / 						(cyclelimit * (sum_lineL1 + sum_lineL2)) << endl;
		cout << " average wait time: "
			<< average_wait << " minutes\n";
	}
	else
		cout << "No customers!\n";

	cout << "We see that the average wait time is approximately" << endl;
	cout << "one minute when there are " << i;
	cout << " customers per minute." << endl;
	
	return 0;
}

//  x = average time, in minutes, between customers
//  return value is true if customer shows up this minute
bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1); 
}
