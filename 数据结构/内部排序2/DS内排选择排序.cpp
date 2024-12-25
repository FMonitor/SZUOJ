#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < n - 1; i++) {
            int minx = arr[i];
            int index = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < minx) {
                    minx = arr[j];
                    index = j;
                }
            }
            if(index!=i)swap(arr[i], arr[index]);
            for (int k = 0; k < n;k++) {
                cout << arr[k];
                if (k != n - 1)cout << " ";
            }
            cout<< endl;
        }
        cout<< endl;
    }
}