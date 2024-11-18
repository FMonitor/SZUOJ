#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7F7F7F7F;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        if (w == other.w) {
            if (u == other.u) return v < other.v;
            return u < other.u;
        }
        return w < other.w;
    }
};

vector<Edge> edges;
int parent[5000], irank[5000];
int n, m, sum;
map<string, int> node;
map<int, string> renode;
stringstream s;
int cnt;

void init() {
    edges.clear();
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        irank[i] = 0;
    }
    sum = 0;
}

int find(int x) {
    if (parent[x] != x) { 
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (irank[rootX] > irank[rootY]) {
            parent[rootY] = rootX;
        } else if (irank[rootX] < irank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            irank[rootX]++;
        }
    }
}

void kruskal() {
    sort(edges.begin(), edges.end());
    for (const auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;
        if (find(u) != find(v)) {
            unionSets(u, v);
            sum += w;
            cnt++;
            if (renode[u] > renode[v]) {
                s << renode[v] << " " << renode[u] << " " << w << endl;
            } else {
                s << renode[u] << " " << renode[v] << " " << w << endl;
            }
            
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
        edges.push_back({node[a], node[b], w});
    }
    kruskal();
    if (cnt != n - 1 || sum==0) {
        cout << -1 << endl;
        return 0;
    }
    cout << sum << endl << s.str();
    return 0;
}