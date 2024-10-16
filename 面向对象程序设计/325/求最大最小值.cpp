#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
void find(int* num, int n, int& minIndex, int& maxIndex) {
    int min = INF, max = -INF;
    for (int i = 0; i < n; i++) {
        if (num[i] < min) {
            min = num[i];
            minIndex = i;
        }
        if (num[i] > max) {
            max = num[i];
            maxIndex = i;
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int* num = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        int minIndex = 0, maxIndex = 0;
        find(num, n, minIndex, maxIndex);
        cout << "min=" << num[minIndex] << " minindex=" << minIndex << endl;
        cout << "max=" << num[maxIndex] << " maxindex=" << maxIndex << endl;
        if (t != 0) cout << endl;
    }
    return 0;
}