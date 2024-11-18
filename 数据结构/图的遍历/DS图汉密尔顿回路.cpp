#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int to, next;
} edge[4000]; 

int n, m;
int head[201]; 
bool vis[201];
int cnt;

void init() {
    for (int i = 0; i <= n; i++) {
        head[i] = -1;
    }
    cnt = 0;
}

void add(int u, int v) {
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

bool isHamiltonianCycle(int arr[], int len) {
    if (len != n + 1 || arr[0] != arr[n]) {
        return false;
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
        vis[arr[i]] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            return false;
        }
    }
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = head[arr[i]]; j != -1; j = edge[j].next) {
            if (edge[j].to == arr[i + 1]) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    int t;
    cin >> t;
    while (t--) {
        int len;
        cin >> len;
        int arr[len];
        for (int i = 0; i < len; i++) {
            cin >> arr[i];
        }
        if (isHamiltonianCycle(arr, len)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}