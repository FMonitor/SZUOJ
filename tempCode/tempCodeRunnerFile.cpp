#include<bits/stdc++.h>
using namespace std;

bool square[100][100];
int m, n, maxn;

int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

void print() {
    for (int i = 1;i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << square[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------" << endl;
}

int dfs(int x, int y, int &cnt) {
    if (square[x][y] == 1) {
        return cnt;
    }
    // print();
    // system("pause");
    cnt++;
    // cout << x <<" "<< y <<" "<<cnt << endl;
    square[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int tmpx = x + dir[i][0];
        int tmpy = y + dir[i][1];
        if (tmpx == 0 || tmpy == 0 || tmpx == m + 1 || tmpy == n + 1) {
            continue;
        }
        dfs(tmpx, tmpy, cnt);
    }
    return cnt;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> square[i][j];
            }
        }
        int tmp = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (square[i][j] == 0 && (i == 1 || i == m || j == 1 || j == n)) {
                    dfs(i, j, tmp);
                    tmp = 0;
                }
                else maxn = max(maxn, dfs(i, j, tmp));
            }
        }
        cout << maxn << endl;
        maxn = 0;
    }

}