#include<bits/stdc++.h>
using namespace std;

class CTime;
class CDate {
private:
    int year;
    int month;
    int day;
public:
    CDate(){};
    CDate(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }
    friend void Display(CDate&, CTime&);
};

class CTime {
private:
    int hour;
    int minute;
    int second;
public:
    CTime(){};
    CTime(int h, int m,int s) {
        hour = h;
        minute = m;
        second = s;
    }
    friend void Display(CDate&, CTime&);
};

void Display(CDate& d, CTime& t) {
    cout << setfill('0') << setw(2) << d.year << "-" 
         << setfill('0') << setw(2) << d.month << "-" 
         << setfill('0') << setw(2) << d.day << " "
         << setfill('0') << setw(2) << t.hour << ":" 
         << setfill('0') << setw(2) << t.minute << ":" 
         << setfill('0') << setw(2) << t.second << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int y, m, day, h, min, s;
        cin >> y >> m >> day >> h >> min >> s;
        CDate d(y, m, day);
        CTime t(h, min, s);
        Display(d, t);
    }
    return 0;
}
