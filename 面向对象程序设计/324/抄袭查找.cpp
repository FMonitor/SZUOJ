#include<bits/stdc++.h>
using namespace std;
struct paper {
    int num;
    string a;
    string b;
    string c;
};
bool check(string a, string b) {
    double cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) cnt++;
    }
    if(cnt / a.size() <= 0.1) return true;
    return false;
}
void cmp(paper* a, paper* b) {
    if ((*a).num == (*b).num) return;
    if (check((*a).a,(*b).a)) {
        cout << (*a).num << " " << (*b).num << " " << 1 << endl;
    }
    if (check((*a).b,(*b).b)) {
        cout << (*a).num << " " << (*b).num << " " << 2 << endl;
    }
    if (check((*a).c,(*b).c)) {
        cout << (*a).num << " " << (*b).num << " " << 3 << endl;
    }
    return;
}
int main() {
    int n;
    cin >> n;
    paper p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i].num >> p[i].a >> p[i].b >> p[i].c;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i;j < n; j++) {
            cmp(p+i, p+j);
        }
    }
    return 0;
}