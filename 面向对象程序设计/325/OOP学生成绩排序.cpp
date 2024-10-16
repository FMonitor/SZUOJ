#include<bits/stdc++.h>
using namespace std;
struct student{
    string name;
    int score1;
    int score2;
    int total;
};
bool cmp(student a, student b) {
    if (a.total != b.total) return a.total < b.total;
    else return a.name < b.name;
}
int main() {
    int n;
    cin >> n;
    student stu[n];
    for (int i = 0; i < n; i++) {
        cin >> stu[i].name >> stu[i].score1 >> stu[i].score2;
        stu[i].total = stu[i].score1 + stu[i].score2;
    }
    sort(stu, stu + n, cmp);
    for(int i = 0; i < n; i++) {
        cout << stu[i].name << " " << stu[i].score1 << " " << stu[i].score2;
        if(i != n - 1) cout << endl;
        else cout << endl;
    }
    return 0;
}