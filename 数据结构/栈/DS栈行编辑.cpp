#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int len = s.length();
        stack<char> str;
        for (int i = 0; i < len; i++) {
            if (s[i] != '#') {
                str.push(s[i]);
            } else {
                if (!str.empty()) {
                    str.pop();
                }
            }
        }
        if (str.empty()) {
            cout << "NULL" << endl;
        } else {
            int index = 0;
            while (!str.empty()) {
                s[index++] = str.top();
                str.pop();
            }
            for (int i =1; i <= index; i++) {
                cout << s[index - i];
            }
            cout << endl;
        }
    }
}