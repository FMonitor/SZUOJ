#include<bits/stdc++.h>
using namespace std;

int matrix[300][300];
bool visited[300];

void DFS(int n, int v) {
    visited[v] = true;
    cout << v << " ";
    for (int i = 0; i < n; i++) {
        if (matrix[v][i] && !visited[i]) {
            DFS(n, i);
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
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                DFS(n, i);
            }
        }
        cout << endl;
    }

    return 0;
}