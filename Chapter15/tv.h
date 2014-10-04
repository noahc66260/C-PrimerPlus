// tv.h -- Tv and Remote classes
// This is exercise 1 of chapter 15 in C++ Primer Plus 5e by Stephen Prata
// Note: this program is a modification of the tv.h file that is listing 15.1

#ifndef TV_H_
#define TV_H_

class Remote;
class Tv
{
public:
    friend class Remote;   // Remote can access Tv private parts
    enum {Off, On};
    enum {MinVal,MaxVal = 20};
    enum {Antenna, Cable};
    enum {TV, VCR};

    Tv(int s = Off, int mc = 100) : state(s), volume(5),
        maxchannel(mc), channel(2), mode(Cable), input(TV) {}
    void onoff() {state = (state == On)? Off : On;}
    bool ison() const {return state == On;}
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() {mode = (mode == Antenna)? Cable : Antenna;}
    void set_input() {input = (input == TV)? VCR : TV;}
    void settings() const; // display all settings
	void toggleRemoteMode(Remote & r) const;
private:
    int state;             // on or off
    int volume;            // assumed to be digitized
    int maxchannel;        // maximum number of channels
    int channel;           // current channel setting
    int mode;              // broadcast or cable
    int input;             // TV or VCR
};

class Remote
{
private:
	int mode_d;           	// controls TV or VCR
	int mode_i; 				// interactive or normal mode
public:
	friend class Tv;
	enum {Normal, Interactive};
	void settings() const;
    Remote(int md = Tv::TV, int mi = Normal) : mode_d(md), mode_i(mi) {}
    bool volup(Tv & t) { return t.volup();}
    bool voldown(Tv & t) { return t.voldown();}
    void onoff(Tv & t) { t.onoff(); }
    void chanup(Tv & t) {t.chanup();}
    void chandown(Tv & t) {t.chandown();}
    void set_chan(Tv & t, int c) {t.channel = c;}
    void set_mode(Tv & t) {t.set_mode();}
    void set_input(Tv & t) {t.set_input();}
};
#endif
