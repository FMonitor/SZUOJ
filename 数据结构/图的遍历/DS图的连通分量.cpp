#include<bits/stdc++.h>
using namespace std;

bool vis[1000];
string point[1000];
int Rmatrix[1000][1000];
int n,m,cnt;
void dfs(int index) {
    if (vis[index]) return;
    vis[index] = 1;
    for (int i = 0; i < n; i++) {
        if (Rmatrix[index][i] == 1) {
            dfs(i);
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
        cin >> n;
        cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> point[i];
            cout << point[i];
            if (i != n - 1) cout << " ";

            vis[i] = 0;
            for (int j = 0; j < n; j++) {
                Rmatrix[i][j] = 0;
            }
        }
        cout << endl;

        cin >> m;
        for (int i = 0; i < m; i++) {
            string a, b;
            cin >> a >> b;
            int indexa, indexb;
            for (int i = 0; i < n; i++) {
                if (point[i] == a) {
                    indexa = i;
                }
                if (point[i] == b) {
                    indexb = i;
                }
            }
            Rmatrix[indexa][indexb] = 1;
            Rmatrix[indexb][indexa] = 1;
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i);
                cnt++;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << Rmatrix[i][j];
                if (j != n - 1) cout << " ";
            }
            cout << endl;
        }
        cout << cnt << "\n\n";
    }
}