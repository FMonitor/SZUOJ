#include<bits/stdc++.h>
using namespace std;

int n, m;
struct Edge {
    int to, next;    
} edge[1000];

int head[1000], cnt;
int disInSixCount[1000];
bool vis[1000];
void addEdge(int u, int v) {
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void init() {
    cnt = 0;
    memset(head, -1, sizeof(head));
}

void dfs(int distance, int u, int start) {
    // cout << distance << " " << u << " " << start << endl;
    if (distance > 0) {
        disInSixCount[start]++;
    }
    if (distance == 6) {
        return;
    }
    vis[u] = true;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if (!vis[v]) {
            dfs(distance + 1, v, start);
        }
    }
    vis[u] = false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    for (int i = 1; i <= n; i++) {
        dfs(0, i, i);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d: %.2f%%\n", i, (double)(disInSixCount[i]+1) / n * 100);
    }
    return 0;
}