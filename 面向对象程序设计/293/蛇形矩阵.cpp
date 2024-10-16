#include<bits/stdc++.h>
using namespace std;
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool mapp[n][n];
        memset(mapp, 0, sizeof(mapp));
        int** p = new int* [n];
        for(int i=0; i<n; i++){
            p[i] = new int[n];
        }
        int x = 0, y = 0;
        int d = 0;
        for (int i = 0; i < n * n; i++) {
            p[x][y] = i + 1;
            mapp[x][y] = 1;
            if (x + dir[d][0] < n && x + dir[d][0] >= 0 && y + dir[d][1] < n && y + dir[d][1] >= 0 && !mapp[x + dir[d][0]][y + dir[d][1]]) {
                x += dir[d][0];
                y += dir[d][1];
            } else {
                d = (d + 1) % 4;
                x += dir[d][0];
                y += dir[d][1];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                 cout << p[i][j];
                if (j != n - 1) cout << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}