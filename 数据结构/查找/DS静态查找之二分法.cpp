#include<bits/stdc++.h>
using namespace std;

void bin_search(int arr[], int n, int target) {
    int l = -1, r = n;
    while (l+1 < r) {
        int mid = (l + r) / 2;
        if (arr[mid] == target) {
            cout << mid+1 << endl;
            return;
        } else if (arr[mid] > target) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << "error" << endl;
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, t;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    cin >> t;
    while (t--) {
        int target;
        cin >> target;
        bin_search(arr, n, target);
    }
}