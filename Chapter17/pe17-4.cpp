// pe17-4.cpp -- description here
// This is exercise 4 of chapter 17 in C++ Primer Plus 5e by Stephen Prata

#include<iostream>
#include<fstream>
#include<cstdlib>

int main(int argc, char * argv[])
{
	using namespace std;

	// check to see that appropriate files exist
	if (argc < 4)
	{
		cerr << "Error, three arguments representing filenames are missing"
			<< endl;
		exit(EXIT_FAILURE);
	}
	else if (argc > 4)
		cerr << "More arguments than necessary are detected" << endl
			<< "Only the first three arguments will be used" << endl;

	cout << "Warning: this will erase the contents of " << argv[3]
		<< ". Proceed? (y/n) ";

	char ch;
	cin >> ch;
	if (ch != 'y' && ch !='Y')
		return 0;
	else
	{
		ifstream infile_first;
		infile_first.open(argv[1]);
		if (!infile_first.is_open())
		{
			cerr << "Error, could not open " << argv[1] << endl;
			exit(EXIT_FAILURE);
		}

		ifstream infile_second;
		infile_second.open(argv[2]);
		if (!infile_second.is_open())
		{
			cerr << "Error, could not open " << argv[2] << endl;
			exit(EXIT_FAILURE);
		}

		ofstream outfile;
		outfile.open(argv[3]);
		if (!outfile.is_open())
		{
			cerr << "Error, could not open " << argv[3] << endl;
			exit(EXIT_FAILURE);
		}

		while (!infile_first.eof() && !infile_second.eof())
		{
			while(infile_first.get(ch) && ch != '\n')
				outfile.put(ch);
			outfile.put(' ');
			while(infile_second.get(ch) && ch != '\n')
				outfile.put(ch);
			outfile.put('\n');
			// In event that file is terminated by \n then EOF, rather than EOF
			infile_first.peek(); // modifies flags if error occurs
			infile_second.peek();
		}
		if (infile_first.eof() && !infile_second.eof())
		{
			while(infile_second.get(ch) && ch != '\n')
				outfile.put(ch);
			outfile.put('\n');
		}
		else if (infile_second.eof() && !infile_first.eof())
		{
			while(infile_first.get(ch) && ch != '\n')
				outfile.put(ch);
			outfile.put('\n');
		}

		infile_first.close();
		infile_second.close();
		outfile.close();
		return 0;
}

	return 0;
}
