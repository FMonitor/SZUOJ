#include<bits/stdc++.h>
using namespace std;
template <class T>
bool check(T *arr) {
    for (int i = 1;i < 6; i++) {
        if (arr[i - 1] > arr[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        char type;
        cin >> type;
        if (type == 'c') {
            char arr[6];
            for (int i = 0; i < 6; i++) {
                cin >> arr[i];
            }
            if (check(arr)) {
                cout << "Valid" << endl;
            } else {
                cout << "Invalid" << endl;
            }
        } else if (type == 'i') {
            int arr[6];
            for (int i = 0; i < 6; i++) {
                cin >> arr[i];
            }
            if (check(arr)) {
                cout << "Valid" << endl;
            } else {
                cout << "Invalid" << endl;
            }
        } else if (type == 'f') {
            double arr[6];
            for (int i = 0; i < 6; i++) {
                cin >> arr[i];
            }
            if (check(arr)) {
                cout << "Valid" << endl;
            } else {
                cout << "Invalid" << endl;
            }
        }
    }
    return 0;
}