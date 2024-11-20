#include<bits/stdc++.h>
using namespace std;

void DFS(int u, vector<vector<double>>& matrix, vector<int>& visited, double current_ratio, double& max_ratio, int start) {
    visited[u] = 1;
    for (int v = 0; v < matrix.size(); v++) {
        if (matrix[u][v] != 0) {
            if (v == start) {
                max_ratio = max(max_ratio, current_ratio * matrix[u][v]);
            } else if (!visited[v]) {
                DFS(v, matrix, visited, current_ratio * matrix[u][v], max_ratio, start);
            }
        }
    }
    visited[u] = 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        map<int, string> mp;
        map<string, int> mp2;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            mp[i] = s;
            mp2[s] = i;
        }

        //货币兑换
        vector<vector<double>> matrix(n, vector<double>(n, 0));
        vector<int> indegree(n, 0);
        for (int i = 0; i < m; i++) {
            string s1, s2;
            double ratio;
            cin >> s1 >> ratio >> s2;
            matrix[mp2[s1]][mp2[s2]] = ratio;
            indegree[mp2[s2]]++;
        }

        //拓扑排序
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                cout << mp[i] << " ";
                for (int j = 0; j < n; j++) {
                    if (matrix[i][j] != 0) {
                        indegree[j]--;
                    }
                }
                indegree[i] = -1;
                i = -1;
            }
        }
        // cout << endl;

        // 使用DFS查找最大的ratio环
        double max_ratio = 1;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (indegree[i] != -1) {
                DFS(i, matrix, visited, 1.0, max_ratio, i);
            }
        }

        if (max_ratio <= 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}