#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;

int main() {
    // int t;
    // cin >> t;
    // while (t--) {
    //     char c, op, y;
    //     int x;
    //     cin >> c >> op >> x >> y;
    //     if (op == '-') {
    //         cout << left << setw(x) << setfill(y) << c;
    //     } else {
    //         cout << right << setw(x) << setfill(y) << c;
    //     }
    //     if (t) cout << endl;
    // }
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    for (auto i : s) {
        cout << i << endl;
    }
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}