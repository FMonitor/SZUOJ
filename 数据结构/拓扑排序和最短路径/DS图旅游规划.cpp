#include<bits/stdc++.h>
using namespace std;
int n, m, s, d;
int head[1010], cnt = 0;
struct edge {
    int to, w, next, len;
}Edge[2010];

void init() {
    for (int i = 0; i < 1010; i++) {
        head[i] = -1;
    }
}

void add(int u,int v,int w,int len) {
    Edge[cnt].to = v;
    Edge[cnt].w = w;
    Edge[cnt].len = len;
    Edge[cnt].next = head[u];
    head[u] = cnt++;
}

void dijkstra() {
    int dis[n];
    int cost[n];
    int vis[n];
    for (int i = 0; i < n; i++) {
        dis[i] = 0x3f3f3f3f;
        cost[i] = 0;
        vis[i] = 0;
    }
    dis[s] = 0;
    for (int i = 0; i < n; i++){
        int u, minn = 0x3f3f3f3f;
        for (int j = 0; j < n; j++) {
            if (dis[j] < minn && !vis[j]) {
                minn = dis[j];
                u = j;
            }
        }
        vis[u] = 1;
        for (int j = head[u]; j != -1; j = Edge[j].next) {
            // cout << "[INFO]Now:" << u << " Next:" << Edge[j].to << " Len:" << Edge[j].len << " W:" << Edge[j].w << endl; 
            if (dis[Edge[j].to] > dis[u] + Edge[j].len) {
                dis[Edge[j].to] = dis[u] + Edge[j].len;
                cost[Edge[j].to] = cost[u] + Edge[j].w;
            } else if (dis[Edge[j].to] == dis[u] + Edge[j].len) {
                cost[Edge[j].to] = min(cost[Edge[j].to], cost[u] + Edge[j].w);
            }
            // cout << "[INFO]Dis:" << dis[Edge[j].to] << " Cost:" << cost[Edge[j].to] << endl;
        }
        // cout << "[INFO]Dis:";
        // for (int j = 0; j < n; j++) {
        //     cout << dis[j] << " ";
        // }
        // cout << endl;
    }
    cout << dis[d] << " " << cost[d] << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cin >> n >> m >> s >> d;//s为起点，d为终点
    init();
    for (int i = 0; i < m; i++) {
        int u, v, w, len;
        cin >> u >> v >> w >> len;
        add(u, v, len,w);
        add(v, u, len,w);
    }
    dijkstra();
}