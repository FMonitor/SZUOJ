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
        int flag = 0;
        int ans = 0;
        for (int k = 0;k < s.size();k++) {
            for (int i = 1;i + k <= s.size();i++) {
                for (int j = i; j + i+k <= s.size(); j++) {
                    string sub1 = s.substr(k, i);
                    string sub2 = s.substr(j+k, i);
                    // cout << sub1 << " " << sub2 << endl;
                    if (sub1 == sub2) {
                        ans = max(ans, i);
                        flag = 1;
                    }
                }
            }
        }

        if (!flag) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}
