#include<bits/stdc++.h>
using namespace std;

int n, m;
bool mapp[105][105];//offset 50x50
bool vis[105][105]; 
queue<pair<int, int>> q;

double dis(double x,double y,double x1,double y1){
    return sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
}

struct node {
    int x, y;
}node[102];

void init() {
    for (int i = 0; i < n; i++) {
        cin >> node[i].x >> node[i].y;
        node[i].x += 50;
        node[i].y += 50;
        mapp[node[i].x][node[i].y] = 1;
        // cout << node[i].x << " " << node[i].y << " " << fabs(dis(node[i].x, node[i].y, 50, 50)) << endl;
        if (fabs(dis(node[i].x, node[i].y, 50, 50)) <= 7.5 + m) {
            q.push({ node[i].x,node[i].y });
        }
    }
    mapp[50][50] = 1;
    vis[50][50] = 1;
    // cout << "init" << endl;
}

void bfs() {
    // cout <<q.empty()<<endl;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        // cout<<x<<" "<<y<<endl;
        vis[x][y] = 1;
        q.pop();
        if(x<=m||y<=m||x>=100-m||y>=100-m){
            cout<<"Yes"<<endl;
            exit(0);
        }
        for (int i = 0; i < n; i++) {
            if (fabs(dis(x, y, node[i].x, node[i].y)) <= m && !vis[node[i].x][node[i].y]) {
                q.push({ node[i].x,node[i].y });
            }
        }
    }
    cout << "No" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> m;
    init();
    bfs();
    return 0;
}