#include<bits/stdc++.h>
using namespace std;
struct square {
    int x1, y1, x2, y2;
};
bool isoverlap(square s1, square s2) {
    if (s1.x2 < s2.x1 || s2.x2 < s1.x1 || s1.y1 > s2.y2 ) {
        return false;
    } else {
        return true;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        square s1, s2;
        cin >> s1.x1 >> s1.y1 >> s1.x2 >> s1.y2;
        cin >> s2.x1 >> s2.y1 >> s2.x2 >> s2.y2;
        if (s1.x1 > s1.x2) swap(s1.x1, s1.x2);
        if (s1.y1 > s2.y2) swap(s1.y1, s1.y2);
        if (s2.x1 > s2.x2) swap(s2.x1, s2.x2);
        if (s2.y1 > s2.y2) swap(s2.y1, s2.y2);
        if (isoverlap(s1, s2)) {
            cout << "overlapped" << endl;
        } else {
            cout << "not overlapped" << endl;
        }
    }
    return 0;
}