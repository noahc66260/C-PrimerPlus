// pe17-7.cpp -- description here
// This is exercise 7 of chapter 17 in C++ Primer Plus 5e by Stephen Prata

#include<iostream> 
#include<cstdlib>
#include<vector>
#include<fstream>
#include<algorithm>

using namespace std;

class Store
{	
private:
	ofstream * pfout;
public:
	Store(ofstream & fout) {pfout = &fout;}
	~Store() {}
	Store & operator()(const string & str)
	{
		size_t len = str.length();
		pfout->write((char *) &len, sizeof(size_t));
		pfout->write(str.data(), len);
		return *this;
	}	
};

void ShowStr(const std::string & str);
void GetStrs(std::ifstream & fin, std::vector<std::string> & vistr);

int main(void)
{
	using namespace std;
	vector<string> vostr;
	string temp;

	// acquire strings
	cout << "Enter strings (empty line to quit):\n";
	while (getline(cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "Here is your input.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);
	
	// store in a file
	ofstream fout("strings.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();

	// recover file contents
	vector<string> vistr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cerr << "Could not open file for input.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	cout << "\nHere are the strings read from the file:\n";
	for_each(vistr.begin(), vistr.end(), ShowStr);

	return 0;
}

void ShowStr(const std::string & str)
{
	using std::cout;
	using std::endl;
	cout << str << endl;
}

void GetStrs(ifstream & fin, vector<string> & vistr)
{
	size_t len;
	string str;
	char ch;
	// check that there is something to read
	while (fin.peek() && !fin.eof()) 
	{
		fin.read((char *) &len, sizeof(size_t));
		for (size_t i = 0; i < len; i++)
		{
			fin.read(&ch, sizeof(char));
			str.push_back(ch);
		}
		vistr.push_back(str);
		str.clear();
	}
}













