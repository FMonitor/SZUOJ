#include<bits/stdc++.h>
using namespace std;

int hashSet[1000];

void Hash(int len, int arr[], int num) {
    for (int i = 0; i < len; i++) {
        hashSet[i] = 99999;
    }
    for (int i = 0; i < num; i++) {
        int now = arr[i] % 11;
        int offset = 0;
        // cout << "now: " << arr[i] << endl;
        while (1) {
            if (now + offset >= len)offset -= len;
            if (hashSet[now + offset] == 99999) {
                hashSet[now + offset] = arr[i];
                // cout << now + offset << endl;
                break;
            }
            offset++;
        }
    }
    for (int i = 0; i < len; i++) {
        if (hashSet[i] == 99999) {
            cout << "NULL";
        } else {
            cout << hashSet[i];
        }
        if (i != len - 1)cout << " ";

    }
    cout << endl;
}

void search(int key, int len) {
    int cnt = 0;
    for (int i = key % 11; i <= len; i++) {
        cnt++;
        if (i == len) i = 0;
        if (hashSet[i] == 99999) {
            cout << 0 << " " << cnt << endl;
            break;
        }
        if (hashSet[i] == key) {
            cout << 1 << " " << cnt << " " << i + 1 << endl;
            break;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif 
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        int keys[n];
        for (int i = 0; i < n; i++) {
            cin >> keys[i];
        }
        Hash(m, keys, n);
        int k;
        cin >> k;
        while (k--) {
            int query;
            cin >> query;
            search(query, m);
        }
    }
}