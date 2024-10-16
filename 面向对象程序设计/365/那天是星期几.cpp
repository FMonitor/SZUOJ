#include<bits/stdc++.h>
using namespace std;
class CDate {
private:
    int month;
    int day;
    int year;
    int week;
    string weekday[8] = { "","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };
public:
    CDate() = default;
    CDate(int, int, int);
    void print();
    void getWeekofDay();
};
CDate::CDate(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}
void CDate::print() {
    cout << month << "/" << day << "/" << year << ", ";
    getWeekofDay();
}
void CDate::getWeekofDay() {
    if (month < 3) {
        month += 12;
        year--;
    }
    int w = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7 + 1;
    cout << weekday[w] << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int year, month, day;
        cin >> year >> month >> day;
        CDate Day = CDate(year, month, day);
        Day.print();
    }
    return 0;
}