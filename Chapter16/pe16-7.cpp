// pe16-7.cpp -- description here
// This is exercise 7 of chapter 16 in C++ Primer Plus 5e by Stephen Prata

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>

using namespace std;
vector<int> Lotto(int spots, int selected);

int main(void)
{
	using namespace std;

	cout << "Enter the number of spots on the lottery card: ";
	int spots;
	cin >> spots;
	cout << "Enter the number of spots to be selected: ";
	int selected;
	cin >> selected;

	vector<int> result = Lotto(spots, selected);
	cout << "Your lucky numbers are: ";
	for (int i = 0; (unsigned) i < result.size(); i++)
		cout << result[i] << " ";
	cout << endl;

	return 0;
}

vector<int> Lotto(int spots, int selected)
{
	if (spots < selected)
	{
		cout << "The second argument of Lotto() must be less than ";
		cout << "the first argument." << endl;
		cout << "Program abort" << endl;
		exit(EXIT_FAILURE);
	}

	if (spots < 0 || selected < 0)
	{
		cout << "Both arguments of Lotto() must be positive integers";
		cout << endl;
		cout << "Program abort" << endl;
		exit(EXIT_FAILURE);		
	}

	vector<int> v;
	for (int i = 1; i < spots + 1; i++)
		v.push_back(i);

	random_shuffle(v.begin(), v.end());
	vector<int> picks;
	for (int i = 0; i < selected; i++)
		picks.push_back(v[i]);

	return picks;
}
