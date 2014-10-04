// pe7-3.cpp -- uses two functions that pass a structure by value and by address
// This is exercise 3 of chapter 7 in C++ Primer Plus by Stephen Prata

#include<iostream>

using namespace std;

struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void displayStructure(box x);
void setVolume(box * y);


int main(void)
{
	cout << "Enter the maker: "; 
	box myBox;
	cin.get(myBox.maker, 40);	

// if I use the getline function the program doesn't work. The only difference is that get does not extract the delimiter. I don't understand why this makes a difference if the input is longer than 40 characters. This is the only way I can get the program to account for input longer than 40 characters. 
	
	while(cin.get() != '\n')
		continue;

	cout << "Enter the height: ";
	cin >> myBox.height;
	cout << "Enter the width: ";
	cin >> myBox.width;
	cout << "Enter the length: ";
	cin >> myBox.length;
	cout << "Enter the volume: ";
	cin >> myBox.volume;

	// display contents of myBox
	cout << endl << "This is what you entered: " << endl;
	displayStructure(myBox);

	// reset volume if volume does not match other dimensions
	if (myBox.volume != myBox.height * myBox.width * myBox.length)
	{
		cout << endl << "It looks like the volume does not correspond to the dimensions appropriately. "
		     << "Let me fix that for you." << endl;
		setVolume(&myBox);		
		cout << "Here are the new corrected dimensions: " << endl;
		displayStructure(myBox);		
	}
	
	cout << endl;
	return 0;
}

// display the contents of the structure
void displayStructure(box x)
{
	cout << "Maker: " << x.maker << endl;
	cout << "Height: " << x.height << endl;
	cout << "Width: " << x.width << endl;
	cout << "Length: " << x.length << endl;
	cout << "Volume: " << x.volume << endl;
	return;
}

// set the volume member to height*width*length
void setVolume(box * y)
{
	y->volume = y->height * y->width * y->length;
	return;
}
