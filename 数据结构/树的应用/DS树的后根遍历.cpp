#include<bits/stdc++.h>
using namespace std;

struct edge {
    int to, next;
}Edge[1000];

struct node {
    char c;
    int id;
}Node[1000];

int Head[1000];
int cnt;

void init() {
    for (int i = 0;i < 1000; i++) {
        Head[i] = -1;
    }
    cnt = 0;
}
void add(int u, int v) {
    Edge[cnt].to = v;
    Edge[cnt].next = Head[u];
    Head[u]=cnt++;
}

void dfs(int root) {
    // cout << Node[root].c << endl;
    for (int i = Head[root]; i != -1; i = Edge[i].next) {
        dfs(Edge[i].to);
    }
    cout << Node[root].c;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, r;
    cin >> n >> r;
    init();
    for (int i = 1; i <= n; i++) {
        cin >> Node[i].c;
        Node[i].id = i;
        int tmp;
        vector<int> rev;
        cin >> tmp;
        while (tmp != -1) {
            rev.push_back(tmp);
            cin >> tmp;
        }
        for (int j = 0; j < rev.size(); j++){
            add(i, rev[rev.size() - j - 1]+1);
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = Head[i]; j != -1; j = Edge[j].next) {
    //         cout << i << " " << Edge[j].to <<" "<<j<< endl;
    //     }
    // }

    dfs(r+1);
    return 0;
}