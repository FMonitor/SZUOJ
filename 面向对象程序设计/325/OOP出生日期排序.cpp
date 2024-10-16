#include<bits/stdc++.h>
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
    int n;
    cin >> n;
    people p[n];
    for (int i=0; i<n; i++) {
        cin >> p[i].year >> p[i].month >> p[i].day;
    }
    sort(p, p + n, cmp);
    for(int i=0; i<n; i++) {
        cout <<i+1<<":"<< p[i].year << "-" << p[i].month << "-" << p[i].day;
        if(i != n - 1) cout << endl;
    }
}