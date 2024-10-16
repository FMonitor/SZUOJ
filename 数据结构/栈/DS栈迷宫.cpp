#include<bits/stdc++.h>
using namespace std;
struct pos {
    int xp;
    int yp;
    pos(int x, int y) {
        xp = x;yp = y;
    }
};
stack<pos> path;
int mymap[1000][1000];
bool check[1000][1000];
int n;
bool flag = 0;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
void dfs(int x, int y) {
    // cout << x << " " << y << endl;
    if (flag) {
        check[x][y] = 0;
        return;
    }
    check[x][y] = 1;
    path.push(pos(x, y));
    if (x == n && y == n) {
        flag = 1;
    }
    for (int i = 0; i < 4; i++) {
        int newX = x + dir[i][0];
        int newY = y + dir[i][1];
        if (newX >= 1 && newX <= n && newY >= 1 && newY <= n) {
            if (!check[newX][newY] && !mymap[newX][newY]) {
                dfs(newX, newY);
            }
        }
    }
    check[x][y] = 0;
    if(!flag)path.pop();
    return;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        memset(check, 0, sizeof(check));
        flag = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> mymap[i][j];
            }
        }
        dfs(1, 1);
        if (!path.empty())//找到路径
        {
            stack<pos> path1;
            while (!path.empty()) {
                path1.push(path.top());
                path.pop();
            }
            int i = 0;  //以下是输出路径的代码
            while (!path1.empty()) {
                pos cpos = path1.top();
                if ((++i) % 4 == 0)
                    cout << '[' << cpos.xp-1 << ',' << cpos.yp-1 << ']' << "--" << endl;
                else
                    cout << '[' << cpos.xp-1 << ',' << cpos.yp-1 << ']' << "--";
                path1.pop();
            }
            cout << "END" << endl;
        } else
            cout << "no path" << endl; //找不到路径输出no path
        while (!path.empty()) {
            path.pop();
        }
    }
    return 0;
},