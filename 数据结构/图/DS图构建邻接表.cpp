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
        int n, k;
        cin >> n >> k;
        vector<int> v[n];
        map<int, char> m;
        map<char, int> m2;
        for (int i = 0; i < n; i++) {
            char tmp;
            cin >> tmp;
            m[i] = tmp;
            m2[tmp] = i;
        }
        while (k--) {
            char node1, node2;
            cin >> node1 >> node2;
            v[m2[node1]].push_back(m2[node2]);
        }
        for (int i = 0; i < n; i++) {
            cout << i << " " << m[i] << "-";
            for (int j = 0; j < v[i].size(); j++) {
                cout << v[i][j] << "-";
            }
            cout << "^" << endl;
        }
    }
    return 0;
}