#include<bits/stdc++.h>
using namespace std;
int n, m, mp[520][520], p[520];

void init() {
    for (int i = 0; i < n; i++)
        p[i] = i;
}

int find(int x) {
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
}

void merge(int x, int y) {
    int xx = find(x);
    int yy = find(y);
    if (xx != yy) p[xx] = yy;
    return;
}


int main() {
    int a, b, k, x, cnt = 0, cnt2, flag = 0;
    cin >> n >> m;
    init();
    while (m--) {
        cin >> a >> b;
        mp[a][b] = 1;
        mp[b][a] = 1;
        merge(a, b);
    }
    for (int i = 0; i < n; i++) {
        if (i == find(i)) cnt++;
    }
    cin >> k;
    if (k == n) flag = 1;
    while (k--) {
        cin >> x;
        init();
        cnt2 = 0;
        for (int i = 0; i < n; i++) mp[x][i] = mp[i][x] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mp[i][j]) merge(i, j);
            }
        }
        for (int i = 0; i < n; i++) {
            if (i == find(i)) cnt2++;
        }
        if (cnt2 <= cnt + 1) cout << "City " << x << " is lost.\n";
        else cout << "Red Alert: City " << x << " is lost!\n";
        cnt = cnt2;
    }
    if (flag) cout << "Game Over." << endl;
    return 0;
}