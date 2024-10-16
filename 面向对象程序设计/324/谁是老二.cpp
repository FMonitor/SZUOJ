#include<iostream>
#include<algorithm>
using namespace std;
struct people {
    int year;
    int month;
    int day;
};
bool cmp(people a, people b) {
    if (a.year != b.year)
        return a.year < b.year;
    if (a.month != b.month)
        return a.month < b.month;
    return a.day < b.day;
}
int main() {
    int t;
    cin >> t;
    people p[t];
    for (int i = 0; i < t; i++) {
        cin >> p[i].year >> p[i].month >> p[i].day;
    }
    sort(p, p + t, cmp);
    cout << p[1].year << "-" << p[1].month << "-" << p[1].day << endl;
    return 0;
}