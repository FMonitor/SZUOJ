#include<bits/stdc++.h>
#define INF 0x7F7F7F7F
using namespace std;

int dis[1000];
int a[1000][1000];
map<string, int> strI;
map<int, string> iStr;
int n, m;
string startStr;
string res[1000];
bool vis[1000];
string conn[1000][2];
bool visk[1000][1000];
int sum = 0;
void prim(int start) {
    vis[start] = 1;
    for (int k = 1; k <= n; k++) {
        string u, v;
        int w = INF;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!vis[j] && a[i][j] < w) {
                        w = a[i][j];
                        u = iStr[i];
                        v = iStr[j];
                    }
                }
            }
        }
        if (w == INF) {
            cout << sum << endl;
            return;
        }
        vis[strI[v]] = 1;
        res[k] = u + " " + v + " " + to_string(w);
        sum += w;
    }
    cout << sum << endl;
}

void kruskal(int start) {
    vis[start] = 1;
    for (int j = 1; j <= n; j++) {
        visk[j][j] = 1;
    }
    for (int i = 1; i < n;i++) {
        int w = INF;
        string u, v;
        for (int j = 1;j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (!visk[j][k] && a[j][k] < w && (!vis[j] || !vis[k])) {
                    // cout << j << k << endl;
                    w = a[j][k];
                    u = iStr[j];
                    v = iStr[k];
                }
            }
        }
        if (w == INF) return;
        visk[strI[u]][strI[v]] = 1;
        visk[strI[v]][strI[u]] = 1;

        conn[i][0] = u;
        conn[i][1] = v;
        cout << u << " " << v << " " << w << endl;
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k <= i; k++) {
                if (vis[strI[conn[k][0]]] || vis[strI[conn[k][1]]]) {
                    // cout << conn[k][0] << " " << conn[k][1] << endl;
                    vis[strI[conn[k][0]]] = 1;
                    vis[strI[conn[k][1]]] = 1;
                }
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    cin >> n;
    memset(a, 0x3f3f3f3f, sizeof(a));
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        strI[s] = i;
        iStr[i] = s;
        a[i][i] = 0;
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        string u, v;
        int w;
        cin >> u >> v >> w;
        a[strI[u]][strI[v]] = w;
        a[strI[v]][strI[u]] = w;
    }
    cin >> startStr;
    prim(strI[startStr]);
    cout << "prim:" << endl;
    for (int i = 1; i < n; i++) cout << res[i] << endl;
    cout << "kruskal:" << endl;
    memset(vis, 0, sizeof(vis));
    kruskal(strI[startStr]);

    return 0;
}