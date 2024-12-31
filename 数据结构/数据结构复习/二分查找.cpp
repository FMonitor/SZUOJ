#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> m;
    while (m--) {
        int query;
        cin >> query;
        int l = -1, r = n;
        int mid = (l + r) >> 1;
        bool flag = 0;
        while (l + 1 < r) {
            mid = (l + r) >> 1;
            // cout << l << " " << r << endl;
            if (arr[mid] < query) {
                l = mid;
            } else if (arr[mid] > query) {
                r = mid;
            } else {
                cout << mid+1 << endl;
                flag = 1;
                break;
            }
            // cout << arr[mid] << " " << query << endl;
        }
        if (!flag)cout << "error" << endl;
    }
    return 0;
}