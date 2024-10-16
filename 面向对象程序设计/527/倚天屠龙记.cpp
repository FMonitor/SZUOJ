#include<bits/stdc++.h>
using namespace std;
template <class T>
void cat(T* arr1, T* arr2, int len) {
    for (int i = len; i < len * 2; i++) {
        arr2[i] = arr1[i - len];
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        char type;
        cin >> type >> n;
        if (type == 'C') {
            char arr1[n]={'0'},arr2[n*2]={'0'};
            for (int i = 0; i < n; i++) {
                cin >> arr1[i];
            }
            for (int i = 0; i < n;i++) {
                cin >> arr2[i];
            }
            cat(arr1, arr2, n);
            for (int i = 0; i < 2 * n; i++) {
                cout << arr2[i];
            }
            cout << endl;
        } else if (type == 'I') {
            int arr1[n],arr2[n*2];
            for (int i = 0; i < n; i++) {
                cin >> arr1[i];
            }
            for (int i = 0; i < n;i++) {
                cin >> arr2[i];
            }
            cat(arr1, arr2, n);
            for (int i = 0; i < 2 * n; i++) {
                cout << arr2[i];
            }
            cout << endl;
        } else if (type == 'D') {
            double arr1[n],arr2[n*2];
            for (int i = 0; i < n; i++) {
                cin >> arr1[i];
            }
            for (int i = 0; i < n;i++) {
                cin >> arr2[i];
            }
            cat(arr1, arr2, n);
            for (int i = 0; i < 2 * n; i++) {
                cout << arr2[i];
            }
            cout << endl;
        }
    }
    return 0;
}

