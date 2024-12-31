#include<bits/stdc++.h>
using namespace std;
int HashSet[1000];
int n, m;
void Hash(int val) {
    int now = val % 11;
    while (HashSet[now]) {
        now++;
        if (now == m)now -= m;
    }
    HashSet[now] = val;
}
int HashQuery(int val,int &pos) {
    int now = val % 11;
    int cnt = 1;
    for (int i = 0; i < m; i++) {
        
        // cout << now << '-';
        if (HashSet[now] == 0) {
            pos = -1;
            return cnt;
        }
        if (HashSet[now] == val) {
            pos = now + 1;
            return cnt;
        }
        now = (now + 1) % m;
        cnt++;
    }
    pos = -1;
    return cnt;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            Hash(arr[i]);
        }
        for (int i = 0;i < m; i++) {
            if (HashSet[i] != 0) cout << HashSet[i];
            else cout << "NULL";
            if (i != m - 1)cout << " ";
        }
        cout << endl;
        int tmp;
        cin >> tmp;
        while (tmp--) {
            int query;
            cin >> query;
            int pos = 0;
            int res = HashQuery(query, pos);
            if (pos != -1) {
                cout << "1 " << res << " " << pos << endl;
            } else {
                cout << "0 " << res << endl;
            }
        }
    }
}