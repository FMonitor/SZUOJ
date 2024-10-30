#include<bits/stdc++.h>
using namespace std;

struct Node
{
    char c;
    int fa;
    bool operator<(Node& a) {
        return fa < a.fa;
    }
}node[1000];

int n;

void dfs(int now) {
    for (int i = 0; i < n; i++) {
        if (node[i].fa == now) {
            cout << node[i].c;
            dfs(i);
        }
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
        for (int i = 0;i < n;i++) {
            cin >> node[i].c;
        }
        for (auto i = 0;i < n; i++) {
            cin >> node[i].fa;
        }
        dfs(-1);
        cout << endl;
    }
}