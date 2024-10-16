#include<bits/stdc++.h>
using namespace std;
struct student {
    string num;
    string name;
    int score1;
    int score2;
    int score3;
    int total;
};
bool cmp(student a, student b) {
    if (a.total != b.total) return a.total > b.total;
    else return a.num < b.num;
}
int main() {
    int n;
    cin >> n;
    student s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i].num >> s[i].name >> s[i].score1 >> s[i].score2 >> s[i].score3;
        s[i].total = s[i].score1 + s[i].score2 + s[i].score3;
    }
    sort(s, s + n, cmp);
    cout << s[0].name << " " << s[0].num << " " << s[0].total << endl;
    return 0;
}