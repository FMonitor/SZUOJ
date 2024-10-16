#include<iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        char a[11];
        char b[11];
        char c[11];
        char ans[31];
        cin >> a >> b >> c;
        
        int index = 0;
        int m, n;
        cin >> m >> n;
        for (int j = m-1; j < n; j++) {
            *(ans + index) = *(a + j);
            index++;
        }
        cin >> m >> n;
        for (int j = m-1; j < n; j++) {
            *(ans + index) = *(b + j);
            index++;
        }
        cin >> m >> n;
        for (int j = m-1; j < n; j++) {
            *(ans + index) = *(c + j);
            index++;
        }
        *(ans + index) = '\0';
        cout << ans << endl;

    }
    return 0;
}