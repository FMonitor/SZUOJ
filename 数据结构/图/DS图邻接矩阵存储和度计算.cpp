#include<iostream>
using namespace std;
#define MAX 0x3f3f3f3f

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        char Type;
        int n, k;
        cin >> Type >> n;
        int matrix[n][n];
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                matrix[i][j] = 0;
            }
        }
        if (Type == 'D') {
            int degree[n][2];
            for(int i=0; i<n; i++) {
                degree[i][0] = degree[i][1] = 0;
            }
            string node[n];
            for (int i = 0; i < n; i++) {
                cin >> node[i];
            }
            cin >> k;
            while (k--) {
                string a, b;
                int x, y;
                cin >> a >> b;
                for (int i = 0; i < n; i++) {
                    if (node[i] == a) x = i;
                    if (node[i] == b) y = i;
                }
                matrix[x][y] = 1;
                degree[x][0]++;
                degree[y][1]++;
            }
            for (int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(j!=n-1) cout << matrix[i][j] << " ";
                    else cout << matrix[i][j];
                }
                cout << endl;
            }
            for (int i = 0; i < n; i++) {
                if (degree[i][0] || degree[i][1]) cout << node[i] << ": " << degree[i][0] << " " << degree[i][1] << " " << degree[i][0] + degree[i][1] << endl;
            }
            for (int i = 0;i < n; i++) {
                if(!degree[i][0] && !degree[i][1]) cout << node[i] << endl;
            }
        } else if (Type == 'U') {
            int degree[n];
            string node[n];
            for (int i = 0; i < n; i++) {
                degree[i] = 0;
                cin >> node[i];
            }
            cin >> k;
            while (k--) {
                string a, b;
                int x, y;
                cin >> a >> b;
                for (int i = 0; i < n; i++) {
                    if (node[i] == a) x = i;
                    if (node[i] == b) y = i;
                }
                matrix[x][y] = matrix[y][x] = 1;
                degree[x]++;
                degree[y]++;
            }
            for (int i=0; i<n; i++) {
                for (int j = 0; j < n; j++) {
                    if(j!=n-1) cout << matrix[i][j] << " ";
                    else cout << matrix[i][j];
                }
                cout << endl;
            }
            for (int i = 0; i < n; i++) {
                if (degree[i]) cout << node[i] << ": " << degree[i] << endl;
            }
            for (int i = 0;i < n; i++) {
                if(!degree[i]) cout << node[i] << endl;
            }
        }
    }
    return 0;
}