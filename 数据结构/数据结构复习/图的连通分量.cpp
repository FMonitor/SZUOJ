#include<bits/stdc++.h>
using namespace std;

int matrix[200][200];
map<string, int> point;
bool vis[200];

void dfs(int a, int n) {
    if (vis[a])return;
    vis[a] = 1;
    for (int i = 1; i <= n; i++) {
        if (matrix[a][i] == 1) {
            dfs(i,n);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        memset(matrix, 0, sizeof(matrix));
        for (int i = 1; i <= n; i++) {
            string a;
            cin >> a;
            point[a] = i;
            vis[i] = 0;
            cout << a;
            if (i != n)cout << " ";
        }
        cout << endl;
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            string a, b;
            cin >> a >> b;
            matrix[point[a]][point[b]] = 1;
            matrix[point[b]][point[a]] = 1;
        }
        for (int i = 1; i <= n; i++ ) {
            for (int j = 1; j <= n; j++) {
                cout << matrix[i][j];
                if (j != n)cout << " ";
            }
            cout << endl;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfs(i,n);
                cnt++;
            }
        }
        cout << cnt << "\n\n";
    }
    return 0;
}