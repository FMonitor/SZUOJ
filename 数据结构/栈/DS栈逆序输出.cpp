#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        int len;
        cin >> str;
        len = str.length();
        stack<char> strings;
        for (int i = 0; i < len; i++) {
            strings.push(str[i]);
        }
        for (int i = 0;i < len;i++) {
            cout << strings.top();
            strings.pop();
        }
        cout << endl;
    }
}