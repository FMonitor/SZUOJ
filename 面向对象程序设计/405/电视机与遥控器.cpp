#include<bits/stdc++.h>
using namespace std;
map<int, string> mstate;
map<int, string> mmode;
map<int, string> minput;
class Tv {
private:
    int state = 0;
    int volume = 0;
    int maxchannel = 100;
    int channel = 0;
    int mode = 0;
    int input = 0;
public:
    Tv(int s, int mc);
    void onoff();
    bool ison() const;
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode();
    void set_input();
    void settings() const;
    friend class Remote;
};
Tv::Tv(int s, int mc) {
    state = s;
    maxchannel = mc;
}
void Tv::onoff() {
    state = (state == 1) ? 0 : 1;
    return;
}
bool Tv::ison() const {
    return state;
}
bool Tv::volup() {
    if (volume == 20)
        return 0;
    volume++;
    return 1;
}
bool Tv::voldown() {
    if (volume == 1)
        return 0;
    volume--;
    return 1;
}
void Tv::chanup() {
    channel++;
    if (channel == maxchannel)
        channel = 1;
    return;
}
void Tv::chandown() {
    channel--;
    if (channel == 0)
        channel = maxchannel;
    return;
}
void Tv::set_mode() {
    mode = (mode == 1) ? 0 : 1;
    return;
}
void Tv::set_input() {
    input = (input == 1) ? 0 : 1;
    return;
}
void Tv::settings() const {
    cout << mstate[state] << " " << volume << " " << channel << " " << mmode[mode] << " " << minput[input];
    return;
}
class Remote {
public:
    bool volup(Tv& t) { return t.volup(); }
    bool voldown(Tv& t) { return t.voldown(); }
    void onoff(Tv& t) { t.onoff(); }
    void chanup(Tv& t) { t.chanup(); }
    void chandown(Tv& t) { t.chandown(); }
    void set_chan(Tv& t, int c) { t.channel = c; }
    void set_mode(Tv& t) { t.set_mode(); }
    void set_input(Tv& t) { t.set_input(); }
};

int main() {
    string state;
    int volume;
    int channel;
    string mode;
    string input;
    cin >> state >> volume >> channel >> mode >> input;
    Tv t(0, 100);
    Remote r;
    mstate[0] = "off";
    mstate[1] = "on";
    mmode[0] = "Antenna";
    mmode[1] = "Cable";
    minput[0] = "TV";
    minput[1] = "VCR";

    if (state == "on") {
        t.onoff();
    }
    for (int i = 0; i < volume; i++) {
        r.volup(t);
    }
    if (mode == "Cable") {
        r.set_mode(t);
    }
    if (input == "VCR") {
        r.set_input(t);
    }
    r.set_chan(t, channel);

    string op;
    while (cin >> op && op != "exit") {
        if(t.ison() == 0 && op != "onoff") {
            continue;
        }
        if (op == "onoff") {
            r.onoff(t);
        } else if (op == "volup") {
            r.volup(t);
        } else if (op == "voldown") {
            r.voldown(t);
        } else if (op == "chanup") {
            r.chanup(t);
        } else if (op == "chandown") {
            r.chandown(t);
        } else if (op == "set_mode") {
            r.set_mode(t);
        } else if (op == "set_input") {
            r.set_input(t);
        } else if (op == "settings") {
            t.settings();
        }
    }
    t.settings();
    return 0;
}