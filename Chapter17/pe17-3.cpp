// pe17-3.cpp -- description here
// This is exercise 3 of chapter 17 in C++ Primer Plus 5e by Stephen Prata

#include<iostream>
#include<fstream>
#include<cstdlib>

int main(int argc, char* argv[])
{
	using namespace std;

	// check to see that appropriate files exist
	if (argc < 3)
	{
		cerr << "Error, two arguments representing filenames are missing"
			<< endl;
		exit(EXIT_FAILURE);
	}
	else if (argc > 3)
		cerr << "More arguments than necessary are detected" << endl
			<< "Only the first two arguments will be used" << endl;

	cout << "Warning: this will erase the contents of " << argv[2]
		<< ". Proceed? (y/n) ";

	char ch;
	cin >> ch;
	if (ch != 'y' && ch !='Y')
		return 0;
	else
	{
		ifstream infile;
		infile.open(argv[1]);
		if (!infile.is_open())
		{
			cerr << "Error, could not open " << argv[1] << endl;
			exit(EXIT_FAILURE);
		}

		ofstream outfile;
		outfile.open(argv[2]);
		if (!outfile.is_open())
		{
			cerr << "Error, could not open " << argv[2] << endl;
			exit(EXIT_FAILURE);
		}

		while (infile.get(ch))
			outfile.put(ch);

		infile.close();
		outfile.close();
		return 0;
	}
}
