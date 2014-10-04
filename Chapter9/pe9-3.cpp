// pe9-3.cpp -- uses new to create an array of two structures 
// in a buffer.
// This is exercise 3 of chapter 9 in C++ Primer Plus by Stephen Prata

#include <iostream>
#include <new>	   // for placement new
#include <cstring> // for strcpy()

struct chaff
{
	char dross[20];
	int slag;
};

// our buffer
chaff buffer[sizeof(chaff) * 2];

int main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::strcpy;
	using std::strlen;

	chaff * pstr = new (buffer) chaff[2];
	int i = 0;
	cout << "Enter the dross name for element " << i + 1 << ": ";
	char dross[20];
	cin.get(dross, 20);

	// prompt user to reenter if string is empty
	while (strlen(dross) == 0)
	{
		cin.clear();
		cin.get();
		cout << "Error. Nothing entered." << endl;
		cout << "Enter dross name for element " 
		     << i + 1 << ": ";
		cin.get(dross, 20);
	}
	
	// discard extra characters
	while (cin.get() != '\n')
		continue;

	strcpy(pstr[i].dross, dross);
	cout << "Enter slag value for element " << i + 1 << ": ";

	// prompt user to reenter if input is incorrect
	while (!(cin >> pstr[i].slag))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "Not an integer." << endl;
		cout << "Enter slag value for element " 
		     << i + 1 << ": ";
	}
	i++;
	cin.get(); 	// discard newline character

	cout << "Enter the dross name for element " << i+1 << ": ";
	cin.get(dross, 20);

	// prompt user to reenter if string is empty
	while (strlen(dross) == 0)
	{
		cin.clear();
		cin.get();
		cout << "Error. Nothing entered." << endl;
		cout << "Enter dross name for element " << i+1 << ": ";
		cin.get(dross, 20);
	}

	// discard extra characters
	while (cin.get() != '\n')
		continue;
	strcpy(pstr[i].dross, dross);
	cout << "Enter slag value for element " << i+1 << ": ";

	// prompt user to reenter if input is incorrect
	while (!(cin >> pstr[i].slag))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "Not an integer." << endl;
		cout << "Enter slag value for element " << i+1 << ": ";
	}
	cin.get(); 	// discard newline character

	// print struct contents in buffer
	for (int j = 0; j < i + 1; j++)
	{
		cout << "Dross for element " << j + 1 << ": "
		     << pstr[j].dross << endl;
		cout << "Slag value: " << pstr[j].slag << endl;
	}

	return 0;
}
