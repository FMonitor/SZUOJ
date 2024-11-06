#include<bits/stdc++.h>
using namespace std;

int matrix[300][300];
bool visited[300];
int n;
queue<int> q;
void BFS(int now) {
    for (int i = 0; i < n; i++) {
        if(matrix[now][i] && !visited[i]) {
            q.push(i);
            cout << i << " ";
            visited[i] = true;
        }
    }
    while (!q.empty()) {
        int next = q.front();
        q.pop();
        BFS(next);
    }
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
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                cout << i << " ";
                visited[i] = true;
                BFS(i);
            }
        }
        cout << endl;
    }

    return 0;
}