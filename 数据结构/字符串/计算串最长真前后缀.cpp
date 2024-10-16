#include<bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (s.size() == 1) {
            cout << "empty" << endl;
        } else {
            int flag = 0;
            string ans;
            for (int i = s.size() - 1;i > 0;i--) {
                string sub1 = s.substr(0, i);
                string sub2 = s.substr(s.size() - i, i);
                // cout << sub1 << " " << sub2 << endl;
                if (sub1 == sub2) {
                    flag = 1;
                    ans = sub1;
                    break;
                } 
            }
            if (flag) {
                cout << ans << endl;
            } else {
                cout << "empty" << endl;
            }
        }
    }
    return 0;
}