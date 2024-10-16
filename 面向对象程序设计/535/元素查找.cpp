#include<bits/stdc++.h>
using namespace std;
template <class T>
int cfind(T* arr, int len, T key) {
    for (int i = 0; i < len; i++) {
        if (arr[i] == key) {
            return i + 1;
        }
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        char type;
        cin >> type >> n;
        if (type == 'I') {
            int arr[n];
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            int target;
            cin >> target;
            cout << cfind(arr, n, target) << endl;
        } else if (type == 'D') {
            double arr[n];
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            double target;
            cin >> target;
            cout << cfind(arr, n, target) << endl;
        } else if (type == 'C') {
            char arr[n];
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            char target;
            cin >> target;
            cout << cfind(arr, n, target) << endl;
        } else if (type == 'S') {
            string arr[n];
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            string target;
            cin >> target;
            cout << cfind(arr, n, target) << endl;
        } 
    }
    return 0;
}