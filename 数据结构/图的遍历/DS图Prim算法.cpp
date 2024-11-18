#include<bits/stdc++.h>
using namespace std;
const int INF = 0x7F7F7F7F;
struct Edge {
    int to, next, w;
}edge[10000];
int head[5000];
int n, m, cnt,sum;
int dis[5000];
bool selected[5000];
map<string, int> node;
map<int, string> renode;
int last[5000];
stringstream s;

void init() {
    for (int i = 0; i < n; i++) {
        head[i] = -1;
        dis[i] = INF;
        selected[i] = 0;
    }
    cnt = 0;
    sum = 0;
}

void add(int u, int v, int w) {
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    edge[cnt].w = w;
    head[u] = cnt++;
}

void prim(int start) {
    selected[start] = 1;
    dis[start] = 0;
    for (int i = start; i < n; ) {
        // cout << "Now is node " << renode[i] << endl;
        for (int j = head[i]; j != -1; j = edge[j].next) {
            if (!selected[edge[j].to]) { 
                if (dis[edge[j].to] > edge[j].w) {
                    dis[edge[j].to] = edge[j].w;
                    last[edge[j].to] = i;
                }
            }
        }

        // cout << "Distance: ";
        // for (int j = 0; j < n; j++) {
        //     cout << dis[j] << " ";
        // }cout << endl;

        int ind = -1;
        int minnum = INF;
        for (int j = 0; j < n; j++) {
            if (selected[j]) continue;
            if (dis[j] < minnum) {
                minnum = dis[j];
                ind = j;
            }
        }
        if (minnum != INF) {
            selected[ind] = 1;
            s << renode[last[ind]] << " " << renode[ind] << " " << dis[ind] << endl;
            sum += dis[ind];
            i = ind;
            // cout << "Selected: " << renode[ind] << " " << ind << endl;
        } else {
            break;
        }
    }

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    init();

    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        node[tmp] = i;
        renode[i] = tmp;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        string a, b;
        int w;
        cin >> a >> b >> w;
        add(node[a], node[b], w);
        add(node[b], node[a], w);
    }
    string h;
    cin >> h;
    prim(node[h]);
    cout << sum << endl << s.str();
}