// pe17-2.cpp -- description here
// This is exercise 2 of chapter 17 in C++ Primer Plus 5e by Stephen Prata

#include<iostream>
#include<fstream>
#include<cstdlib>

int main(int argc, char* argv[])
{
	using namespace std;
	
	// check for input on command line
	if (argc == 1)
	{
		cerr << "Error, a filename must be an argument on the command line."
			<< endl;
		exit(EXIT_FAILURE);
	}

	// tell user that only one file is used if multiple arguments
	if (argc > 2)
		cout << "Arguments on the command line beyond the first are ignored"
			<< endl;

	ofstream outfile;
	outfile.open(argv[1]); // How do I check if I'm rewriting an extant file?
	if (!outfile.is_open())
	{
		cerr << "Error, could not open file." << endl;
		exit(EXIT_FAILURE);
	}

	cout << "Enter input (ctrl-D when done): ";
	char ch;

	while (cin.get(ch))
		outfile.put(ch);
	if (!cin.eof())
		cerr << "Warning, input quit due to something other than "
			<< "simulated EOF" << endl;

	outfile.close();
	return 0;
}
