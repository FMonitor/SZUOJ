#include<iostream>
using namespace std;

void insertSort(int arr[],int n) {
    int i, j, tmp;
    for (i = 0; i < n-1; i++) {
        tmp = arr[i+1];
        for (j = i; j >= 0;j--) {
            if (arr[j] > tmp) {
                swap(arr[j + 1],arr[j]);
            } else {
                break;
            }
        }
        for (int j = 0; j < n; j++) {
            cout << arr[j];
            if (j != n - 1)cout << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    insertSort(arr, n);
    return 0;
}