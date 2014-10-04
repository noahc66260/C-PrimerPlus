// pe16-8.cpp -- description here
// This is exercise 8 of chapter 16 in C++ Primer Plus 5e by Stephen Prata

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cctype>

using namespace std;

bool string_compare(string s1, string s2);

int main(void)
{
	cout << "Enter Mat's list of friends ";
	cout << "(enter after each name, quit to quit):\n";
	vector<string> mat_list;
	string name;
	getline(cin, name);
	while (name != "quit")
	{
		if (name != "")
			mat_list.push_back(name);
		getline(cin, name);
	}
	
	cout << "Enter Pat's list of friends ";
	cout << "(enter after each name, quit to quit):\n";
	vector<string> pat_list;
	getline(cin, name);
	while (name != "quit")
	{
		if (name != "")
			pat_list.push_back(name);
		getline(cin, name);
	}

	sort(mat_list.begin(), mat_list.end(), string_compare);
	sort(pat_list.begin(), pat_list.end(), string_compare);
	vector<string> merged_list;
	insert_iterator< vector<string> > 
		insert(merged_list, merged_list.begin() );
	set_union(mat_list.begin(), 
		mat_list.end(), 
		pat_list.begin(),
		pat_list.end(), 
		insert,
		string_compare);

	cout << "Here is our guestlist: " << endl;
	for (int i = 0; (unsigned) i < merged_list.size(); i++)
		cout << merged_list[i] << endl;

	return 0;
}

bool string_compare(string s1, string s2)
{
	transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
	return s1 < s2;
}
