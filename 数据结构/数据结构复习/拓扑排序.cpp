#include<bits/stdc++.h>
using namespace std;
int n;
int matrix[1000][1000];
int cnt[1000];
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif 
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cnt[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> matrix[i][j];
                if (matrix[i][j] == 1) cnt[j]++;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cnt[j] == 0) {
                    for (int k = 1; k <= n; k++) {
                        if (matrix[j][k] == 1) {
                            cnt[k]--;
                            matrix[j][k] = 0;
                        }
                    }
                    cout << j - 1 << " ";
                    cnt[j]--;
                    break;
                }
            }
        }
        cout << endl;
    }
}