#include<bits/stdc++.h>
using namespace std;

int mat[1000][1000];
bool vis[1000];
int n;
vector<int> res;

void dfs(int now) {
    res.push_back(now);
    vis[now] = 1; 
    for (int i = 1; i <= n; i++) {          
        if (!vis[i] && mat[now][i] == 1) {

            dfs(i);
        }
    }
}

int main() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mat[i][j];
        }
    }
    int m;
    cin >> m;
    dfs(m + 1);
    for (int i = 1; i <= n; i++) {
        if (!vis[i])dfs(i);
    }
    cout << "DFS from " << m << ": ";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i]-1;
        if (i != res.size() - 1) cout << " ";
    }
}