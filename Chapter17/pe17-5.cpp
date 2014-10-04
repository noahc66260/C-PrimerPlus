// pe17-5.cpp -- description here
// This is exercise 5 of chapter 17 in C++ Primer Plus 5e by Stephen Prata

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<iterator>
#include<cctype>

using namespace std;

void check(ifstream & infile, string filename);
void check(ofstream & infile, string filename);
bool stringComp(string s1, string s2); // case insensitive < comparison
bool stringEqual(string s1, string s2); // case insensitive == comparison

int main(void)
{

	ifstream patfile("pat.dat");
	ifstream matfile("mat.dat");
	check(patfile, "pat.dat");
	check(matfile, "mat.dat");
	string name;
	vector<string> patlist;
	vector<string> matlist;

	while (getline(patfile, name) && name != "")
		patlist.push_back(name);
	while (getline(matfile, name) && name != "")
		matlist.push_back(name);

	vector<string> matnpat_list;
	back_insert_iterator< vector<string> > iiter(matnpat_list);
	copy(patlist.begin(), patlist.end(), iiter);
	copy(matlist.begin(), matlist.end(), iiter);
	sort(matnpat_list.begin(), matnpat_list.end(), stringComp);
	vector<string>::iterator iv = 
		unique(matnpat_list.begin(), matnpat_list.end(), stringEqual);
	matnpat_list.erase(iv, matnpat_list.end());
	ostream_iterator<string> os_iter (cout, "\n");
	
	cout << "Here is your list of guests: " << endl;
	copy(matnpat_list.begin(), matnpat_list.end(), os_iter);

	return 0;
}

void check(ifstream & infile, string filename)
{
	if (!infile.is_open())
	{
		cerr << "Error, cannot open " << filename << endl;
		exit(EXIT_FAILURE);
	}
}

void check(ofstream & infile, string filename)
{
	if (!infile.is_open())
	{
		cerr << "Error, cannot open " << filename << endl;
		exit(EXIT_FAILURE);
	}
}

bool stringComp(string s1, string s2)
{
	transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
	return s1 < s2;
}

bool stringEqual(string s1, string s2)
{
	transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
	return s1 == s2;
}
