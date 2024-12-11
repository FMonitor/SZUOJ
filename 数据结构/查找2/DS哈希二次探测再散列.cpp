#include<bits/stdc++.h>
using namespace std;

int hashSet[1000];

void Hash(int len, int arr[], int num) {
    for (int i = 0; i < len; i++) {
        hashSet[i] = -1;
    }
    for (int i = 0; i < num; i++) {
        int now = arr[i] % 11;
        int offset = 0;
        // cout << "now: " << arr[i] << " " << now << endl;
        while (1) {
            int poff = offset * offset;
            if (hashSet[(now + poff) % len] == -1) {
                hashSet[(now + poff) % len] = arr[i];
                break;
            } else if (hashSet[(now - poff + len) % len] == -1) {
                hashSet[(now - poff + len) % len] = arr[i];
                break;
            }
            offset++;
        }
        // cout << endl;
    }
    for (int i = 0; i < len; i++) {
        if (hashSet[i] == -1) {
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
    int offset = 0;
    while (1) {
        cnt++;
        int now = key % 11;
        int poff = offset * offset;
        if (hashSet[(now + poff) % len] == -1) {
            cout << 0 << " " << cnt << endl;
            break;
        }
        if (hashSet[(now + poff) % len] == key) {
            cout << 1 << " " << cnt << " " << (now + poff)%len+1 << endl;
            break;
        }
        if(poff!=0)cnt++;
        if (hashSet[(now - poff + len) % len] == -1) {
            cout << 0 << " " << cnt << endl;
            break;
        }
        if (hashSet[(now - poff + len) % len] == key) {
            cout << 1 << " " << cnt << " " << (now -poff+len)%len+1 << endl;
            break;
        }
        offset++;
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