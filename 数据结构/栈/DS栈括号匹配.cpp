#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<char> c;
        bool isError = false;
        for (int i = 0; i < s.length();i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                c.push(s[i]);
            } else if(s[i]==')'||s[i]==']'||s[i]=='}'){
                if (c.empty()) {
                    cout << "error" << endl;
                    isError = true;
                    break;
                }
                if (s[i] == ')' && c.top() == '(' ||
                    s[i] == ']' && c.top() == '[' ||
                    s[i] == '}' && c.top() == '{') {
                    c.pop();
                } else {
                    cout << "error" << endl;
                    isError = true;
                    break;
                }
            }
        }
        if (!isError) {
            if (c.empty()) {
                cout << "ok" << endl;
            } else {
                cout << "error" << endl;
            }
        }
    }
    return 0;
}