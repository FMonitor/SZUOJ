#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList;
vector<int> nodesToCalculate;

double calculateClosenessCentrality(int node, int N) {
    vector<int> dist(N + 1, INT_MAX);
    queue<int> q;
    dist[node] = 0;
    q.push(node);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adjList[u]) {
            if (dist[v] == INT_MAX) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    double sumDist = 0;
    int reachableNodes = 0;
    for (int i = 1; i <= N; ++i) {
        if (i != node && dist[i] != INT_MAX) {
            sumDist += dist[i];
            reachableNodes++;
        }
    }

    if (reachableNodes == 0) return 0.0;
    return reachableNodes / sumDist;
}

int main() {
    int N, M;
    cin >> N >> M;

    adjList.resize(N + 1);

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int K;
    cin >> K;
    nodesToCalculate.resize(K);
    for (int i = 0; i < K; ++i) {
        cin >> nodesToCalculate[i];
    }

    for (int node : nodesToCalculate) {
        double closenessCentrality = calculateClosenessCentrality(node, N);
        cout << "Cc(" << node << ")=" << fixed << setprecision(2) << closenessCentrality << endl;
    }

    return 0;
}