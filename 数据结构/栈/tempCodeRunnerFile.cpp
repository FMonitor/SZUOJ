#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<char> c;
        for (int i = 0; i < s.length();i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                c.push(s[i]);
            } else if (s[i] == ')') {
                if (!c.empty()&&c.top() == '(' ) {
                    c.pop();
                } else {
                    cout << "error" << endl;
                    break;
                }
            } else if (s[i] == ']') {
                if (!c.empty()&&c.top() == '[' ) {
                    c.pop();
                } else {
                    cout << "error" << endl;
                    break;
                }
            } else if (s[i] == '}' ) {
                if (!c.empty()&&c.top() == '{') {
                    c.pop();
                } else {
                    cout << "error" << endl;
                    break;
                }
            }
        }
        if (c.empty()) {
            cout << "ok" << endl;
        } else {
            cout << "error" << endl;
        }
    }
    return 0;
}