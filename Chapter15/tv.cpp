// tv.cpp -- methods for the Tv class (Remote methods are inline)
// This is exercise 1 of chapter 15 in C++ Primer Plus 5e by Stephen Prata
// Note: this program is a modification of the tv.cpp file that is listing 15.2

#include <iostream>
#include "tv.h"

bool Tv::volup()
{
    if (volume < MaxVal)
    {
        volume++;
        return true;
    }
    else
        return false;
}
bool Tv::voldown()
{
    if (volume > MinVal)
    {
        volume--;
        return true;
    }
    else
        return false;
}

void Tv::chanup()
{
    if (channel < maxchannel)
        channel++;
    else
        channel = 1;
}

void Tv::chandown()
{
    if (channel > 1)
        channel--;
    else
        channel = maxchannel;
}

void Tv::settings() const
{
    using std::cout;
    using std::endl;
    cout << "TV is " << (state == Off? "Off" : "On") << endl;
    if (state == On)
    {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = "
            << (mode == Antenna? "antenna" : "cable") << endl;
        cout << "Input = "
            << (input == TV? "TV" : "VCR") << endl;
    }
}

void Tv::toggleRemoteMode(Remote & r) const
{
	if (On == state && r.mode_i == Remote::Interactive)
		r.mode_i = Remote::Normal; // is this OK?
	else if (On == state && r.mode_i == Remote::Normal)
		r.mode_i = Remote::Interactive;
	else
		return;
}

void Remote::settings() const
{
	using std::cout;
	using std::endl;
	cout << "Remote is set to the " << 
		(mode_d == Tv::TV ? "TV" : "VCR");
	cout << " and is in " << 
		(mode_i == Normal ? "Normal" : "Interactive") << " mode" << endl; 
}
