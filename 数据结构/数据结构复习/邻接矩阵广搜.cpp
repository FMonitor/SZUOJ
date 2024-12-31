#include<bits/stdc++.h>
using namespace std;

int mat[1000][1000];
bool vis[1000];
int n, m;
vector<int> res;
void bfs(int now) {
    queue<int> q;
    q.push(now);
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        if(!vis[tmp])res.push_back(tmp);
        vis[tmp] = 1;
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && mat[tmp][i] == 1) {
                q.push(i);
            }
        }
        
    }
}

int main() {
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        mat[a+1][b+1] = 1;
        mat[b+1][a+1] = 1;
    }
    cin >> m;
    bfs(m + 1);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) bfs(i);
    }
    cout << "BFS from " << m << ": ";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i]-1;
        if (i != res.size() - 1) cout << " ";
    }
}