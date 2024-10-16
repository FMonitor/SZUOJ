#include<iostream>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        int** p = new int* [m];
        for (int i = 0; i < m; i++) {
            p[i] = new int[n];
        }
        int maxans = -INF;
        int minans = INF;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> p[i][j];
                maxans = max(maxans, p[i][j]);
                minans = min(minans, p[i][j]);
            }
        }
        cout << minans << " " << maxans << endl;
    }
    return 0;
}