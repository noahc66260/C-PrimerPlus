// pe15-3.cpp -- Uses exceptions to throw logic_error derived objects
// This is exercise 3 of chapter 15 in C++ Primer Plus 5e by Stephen Prata
// Note: This is a modified version of error4.cpp or listing 15.11
#include <iostream>
#include <cmath> // or math.h, unix users may need -lm flag
#include<stdexcept> 
#include<typeinfo> // for typeid()
double hmean(double a, double b) throw(std::logic_error);
double gmean(double a, double b) throw(std::logic_error);

using std::string;

class bad_hmean : public std::invalid_argument
{
private:
	int arg1;
	int arg2;
public:
	bad_hmean(int a, int b, const string & s = "") 
		: std::invalid_argument(s), arg1(a), arg2(b) {}
	void display() const;
};

void bad_hmean::display() const
{
	using std::cout;
	using std::endl;
	cout << "For function hmean(): " << endl;
	cout << "Invalid arguments: \"a\" and \"b\" must be equal." << endl;
	cout << "You entered a = " << arg1 << ", b = " << arg2 << endl;
}

class bad_gmean : public std::domain_error
{
private:
	int arg1;
	int arg2;
public:
	bad_gmean(int a, int b, const string & s = "") 
		: std::domain_error(s), arg1(a), arg2(b) {}
	void display() const;
};

void bad_gmean::display() const
{
	using std::cout;
	using std::endl;

	cout << "For function gmean(): " << endl;
	cout << "Invalid arguments: \"a\" and \"b\" "
		<< "must be nonnegative." << endl;
	cout << "You entered a = " << arg1 << ", b = " << arg2 << endl;
}

int main()
{
	using namespace std;
    
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
		catch (exception & e) 
		{
			if ( typeid(bad_hmean &) == typeid(e) )
			{
				bad_hmean & bhm = dynamic_cast<bad_hmean &>(e);
				bhm.display();
			}
			else if ( typeid(bad_gmean &) == typeid(e) )
			{
				bad_gmean & bgm = dynamic_cast<bad_gmean &>(e);
				bgm.display();
			}
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
        throw bad_hmean(a, b);
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) throw(std::logic_error)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a,b);
    return std::sqrt(a * b); 
}

