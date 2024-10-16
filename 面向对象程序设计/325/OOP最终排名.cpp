#include<bits/stdc++.h>
using namespace std;
struct team {
    int id;
    int score;
    int pos;
};
bool cmp(team a, team b) {
    if (a.score != b.score) return a.score > b.score;
    else return a.pos < b.pos;
}
int main() {
    int n;
    cin >> n;
    team t[n];
    for (int i = 0; i < n; i++) {
        cin >> t[i].id >> t[i].score;
        t[i].pos = i;
    }
    sort(t, t + n, cmp);
    for(int i = 0; i < n; i++) {
        cout << t[i].id << " " << t[i].score << endl;
    }
    return 0;
}