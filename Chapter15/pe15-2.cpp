// pe15-2.cpp -- Uses exceptions to throw logic_error derived objects
// This is exercise 2 of chapter 15 in C++ Primer Plus 5e by Stephen Prata
// Note: This is a modified version of error4.cpp or listing 15.11
#include <iostream>
#include <cmath> // or math.h, unix users may need -lm flag
#include<stdexcept> 
double hmean(double a, double b) throw(std::logic_error);
double gmean(double a, double b) throw(std::logic_error);
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
	using std::logic_error;
	using std::invalid_argument;
	using std::domain_error;
    
    double x, y, z;

    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        try {                  // start of try block
            z = hmean(x,y);
            cout << "Harmonic mean of " << x << " and " << y
                << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y
                << " is " << gmean(x,y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }// end of try block
        catch (invalid_argument & ia)    // start of catch block
        {
            cout << ia.what() << endl;
            cout << "Try again.\n";
            continue;
        }                  
        catch (domain_error & de) 
        {
            cout << de.what() << endl;
            cout << "Sorry, you don't get to play any more.\n";
            break;
        } // end of catch block
    }
    cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b) throw(std::logic_error)
{
    if (a == -b)
        throw std::invalid_argument
				("Error in hmean(): values are equal");
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) throw(std::logic_error)
{
    if (a < 0 || b < 0)
        throw std::domain_error
				("Error in gmean(): both values must be positive");
    return std::sqrt(a * b); 
}

