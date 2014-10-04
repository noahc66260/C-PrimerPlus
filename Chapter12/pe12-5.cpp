// pe12-5.cpp -- finds the maximum number of customers per minute such that
// the average wait time is less than or equal to a minute.
// Note: this program uses code from listing 12.12
// This is exercise 5 of chapter 12 in C++ Primer Plus by Stephen Prata
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

	 long turnaways;
	 long customers;     //  joined the queue
	 long served;        //  served during the simulation
	 long sum_line;      //  cumulative line length
	 int wait_time;      //  time until autoteller is free
	 long line_wait;     //  cumulative time in line

	int i = 60; 	// we know that with 60 people per hour
						// the average wait time will be longer
						// than 1 minute per person.
	do
	{
	    perhour = i--;	// we will update i for each loop
	    Queue line(hours * perhour);
			// we set our queue size to the total number of 
			// customers we expect to see in our simulation
			// so that none of them are turned away.
		 min_per_cust = MIN_PER_HR / perhour;
		 turnaways = 0;		// turned away
		 customers = 0;     //  joined the queue
		 served = 0;        //  served during the simulation
		 sum_line = 0;      //  cumulative line length
		 wait_time = 0;      //  time until autoteller is free
		 line_wait = 0;     //  cumulative time in line

	// running the simulation
		 for (int cycle = 0; cycle < cyclelimit; cycle++)
		 {
		     if (newcustomer(min_per_cust))  // have newcomer
		     {
		         if (line.isfull())
		             turnaways++;
		         else
		         {
		             customers++;
		             temp.set(cycle);    // cycle = time of arrival
		             line.enqueue(temp); // add newcomer to line
		         }
		     }
		     if (wait_time == 0 && !line.isempty())
		     {
		         line.dequeue (temp);      // attend next customer
		         wait_time = temp.ptime(); // for wait_time minutes
		         line_wait += cycle - temp.when();
		         served++;
		     }
		     if (wait_time > 0)
		         wait_time--;
		     sum_line += line.queuecount();
		 }
	    line.~Queue();
	}
	while ((double) line_wait / served > 1.0);
	i++; // account for decrement of i on last loop

// reporting results
    if (customers > 0)
    {
        cout << "customers per hour: " << i << endl;
        cout << "customers accepted: " << customers << endl;
        cout << "  customers served: " << served << endl;
        cout << "         turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout.setf(ios_base::showpoint);
        cout << (double) sum_line / cyclelimit << endl;
        cout << " average wait time: "
             << (double) line_wait / served << " minutes\n";
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
