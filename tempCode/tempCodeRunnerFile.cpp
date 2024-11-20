#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

int n, matrix[501][501];
string vertex[501], point;
int dist[501][501];
int nextNode[501][501];

void floydWarshall() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = matrix[i][j];
            if (matrix[i][j] != INF && i != j) {
                nextNode[i][j] = j;
            } else {
                nextNode[i][j] = -1;
            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    nextNode[i][j] = nextNode[i][k];
                }
            }
        }
    }
}

vector<int> getPath(int u, int v) {
    if (nextNode[u][v] == -1) return {};
    vector<int> path = {u};
    while (u != v) {
        u = nextNode[u][v];
        path.push_back(u);
    }
    return path;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> vertex[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
                if (matrix[i][j] == 0 && i != j) matrix[i][j] = INF;
            }
        }
        cin >> point;
        int m;
        for (int i = 0; i < n; i++) {
            if (vertex[i] == point) {
                m = i;
                break;
            }
        }
        floydWarshall();
        for (int i = 0; i < n; i++) {
            if (i == m) continue;
            if(dist[m][i] == INF) {
                cout << vertex[m] << "-" << vertex[i] <<"--"<<1 << "\n";
                continue;
            }
            vector<int> path = getPath(m, i);
            cout << vertex[m] << "-" << vertex[i] << "-" << dist[m][i] << "----[";
            for (int k = 0; k < path.size(); k++) {
                cout << vertex[path[k]] << " ";
            }
            cout << "]\n";
        }
    }
    return 0;
}