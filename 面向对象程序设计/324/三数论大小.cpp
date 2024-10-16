#include<bits/stdc++.h>
using namespace std;
void compare(int& a, int& b, int& c) {
    if (a < b) swap(a, b);
    if (a < c) swap(a, c);
    if (b < c) swap(b, c);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int &ra = a, &rb = b, &rc = c;
        compare(ra, rb, rc);
        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}