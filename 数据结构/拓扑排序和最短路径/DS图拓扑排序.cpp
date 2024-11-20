#include<iostream>
using namespace std;
int n, matrix[100][100];
int vec[100], vis[100];

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
            vec[i] = 0;
            vis[i] = 0;
            for (int j = 0;j < n;j++)
                matrix[i][j] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
                if (matrix[i][j] == 1)
                    vec[j]++;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << vec[j] << " ";
            
            if (!vis[i] && vec[i] == 0) {
                cout << i << " ";
                vec[i] = -1;
                vis[i] = 1;
                for (int j = 0; j < n; j++) {
                    if (matrix[i][j] == 1) {
                        vec[j]--;
                        matrix[i][j]--;
                    }
                }
                i = -1;
            }
        }
        cout << endl;
    }
}