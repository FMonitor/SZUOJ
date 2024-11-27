#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int target) {
    for (int i = n; i >= 0; i--) {
        if(arr[i] == target) {
            if (i == 0) {
                cout << "error" << endl;
                return 0;
            }
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, t;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    cin >> t;
    while (t--) {
        cin >> arr[0];
        search(arr, n, arr[0]);
    }
    return 0;
}