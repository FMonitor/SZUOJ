#include<bits/stdc++.h>
using namespace std;
class Date {
protected:
    int year;
    int month;
    int day;
public:
    Date(){}
    Date(int y, int  m, int d) :year(y), month(m), day(d) {}
};

class Time {
protected:
    int hour;
    int minute;
    int second;
public:
    Time(){}
    Time(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }
};

class Schedule : public Date, public Time {
protected:
    int ID;
public:
    Schedule(){}
    friend bool before(const Schedule& s1, const Schedule& s2);
    Schedule(int id, int y, int m, int d, int h, int min, int s) :Date(y, m, d), Time(h, min, s), ID(id) {}
    void Display() {
        cout << "The urgent schedule is No." << ID << ": "
            << year << "/" << setw(2) << setfill('0')<< month << "/"
            << setw(2) << setfill('0') << day << " "
            << setw(2) << setfill('0') << hour << ":"
            << setw(2) << setfill('0') << minute << ":"
            << setw(2) << setfill('0') << second;
    }
};

bool before(const Schedule& s1, const Schedule& s2) {
    if (s1.year != s2.year) {
        return s1.year < s2.year;
    }
    if (s1.month != s2.month) {
        return s1.month < s2.month;
    }
    if (s1.day != s2.day) {
        return s1.day < s2.day;
    }
    if (s1.hour != s2.hour) {
        return s1.hour < s2.hour;
    }
    if (s1.minute != s2.minute) {
        return s1.minute < s2.minute;
    }
    if (s1.second != s2.second) {
        return s1.second < s2.second;
    }
    return s1.ID < s2.ID;
}

int main() {
    int id, y, m, d, h, min, s;
    
    cin >> id >> y >> m >> d >> h >> min >> s;
    Schedule s0(id, y, m, d, h, min, s);
    while (1) {
        cin >> id;
        if (!id) break;
        cin >> y >> m >> d >> h >> min >> s;
        Schedule s1(id, y, m, d, h, min, s);
        if (!before(s0, s1)) {
            s0 = s1;
        }
    }
    s0.Display();
    return 0;
}