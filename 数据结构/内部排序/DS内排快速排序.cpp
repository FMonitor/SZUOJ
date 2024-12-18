#include<iostream>
#include<windows.h>
using namespace std;

int arr[5010];

void fastSort(int l, int r, int n) {
    // system("pause");
    // cout << l << " " << r << endl;
    if (l >= r)return;
    int ll = l, rr = r;
    int pivot = arr[l];
    bool mode = 0;
    while (l < r) {
        if (mode == 0) {
            if (arr[r] >= pivot) {
                r--;
                continue;
            } else {
                arr[l] = arr[r];
                mode = 1;
            }
        } else {
            if (arr[l] <= pivot) {
                l++;
                continue;
            } else {
                arr[r] = arr[l];
                mode = 0;
            }
        }
    }
    arr[l] = pivot;
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1)cout << " ";
    }
    cout << endl;
    fastSort(ll, l - 1, n);
    fastSort(r + 1, rr, n);
    return;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        fastSort(0, n - 1, n);
        cout << endl; 
    }
    return 0;
}