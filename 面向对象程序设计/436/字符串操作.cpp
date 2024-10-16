#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    string op;
    string cpy;
    while (cin >> op) {
        if (op == "copy") {
            int n, x, l;
            cin >> n >> x >> l;
            cpy = s[n].substr(x, l);
        }
    }
    return 0;
}