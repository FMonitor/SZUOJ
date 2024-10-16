#include<bits/stdc++.h>
using namespace std;
class CDate {
private:
    int year, month, day;
public:
    CDate(int y, int m, int d) { year = y; month = m; day = d; }
    bool isLeapYear() { return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; }
    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }
    int getDayofYear()         //计算日期从当年1月1日算起的天数
    {
        int i, sum = day;
        int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
        int b[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };

        if (isLeapYear())
            for (i = 0;i < month;i++)   sum += b[i];
        else
            for (i = 0;i < month;i++)   sum += a[i];

        return sum;
    }
};
CDate today(2015, 4, 7);
class Software {
private:
    string name;
    string type;
    CDate* date;//since 2015-4-7
    string media;
    bool limit = 1;
public:
    Software(string n, string t, int y, int m, int d, string me) {
        name = n;
        if (t == "O") {
            type = "original";
        }
        else if (t == "T") {
            type = "trial";
            if (CDate(y, m, d).getDayofYear() - today.getDayofYear() > 30) {
            }
        }
        else if (t == "B") {
            type = "backup";
        }
        date = new CDate(y, m, d);
        if (y == 0 && m == 0 && d == 0) {
            limit = 0;
        }
        if(me == "D") {
            media = "optical disk";
        }
        else if (me == "H") {
            media = "hard disk";
        }
        else if (me == "U") {
            media = "USB disk";
        }
        else {
            media = "unknown";
        }
    }
    Software(const Software& s) {
        name = s.name;
        type = "backup";
        date = new CDate(s.date->getYear(), s.date->getMonth(), s.date->getDay());
        media = s.media;
    }
    void print() {
        cout << "name:"<<name << "\ntype:" << type << "\n"<<"media:"<<media << "\n";
        if (date->getDayofYear() < today.getDayofYear()) {
            cout << "this software has expired\n\n";
        }
        else if (!limit) {
            cout << "this software has unlimited use\n\n";
        } else {
            cout <<"this software is going to be expired in " << date->getDayofYear() << "days\n\n" ;
        }
    }
    ~Software() {
        delete date;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        string name, type, media;
        int y, m, d;
        cin >> name >> type>> media >> y >> m >> d ;
        Software s(name, type, y, m, d, media);
        s.print();
        Software s2 = s;
        s2.print();
    }
}