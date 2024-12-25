#include<bits/stdc++.h>
using namespace std;

void HeapAdjust(int arr[], int start, int end) {
    int tmp = arr[start];
    int j = 0;
    for (j = 2 * start; j <= end; j *= 2) {
        if (j < end && arr[j + 1] < arr[j]) {
            j++;
        }
        if (tmp < arr[j]) {
            break;
        }
        arr[start] = arr[j];
        start = j;
    }
    arr[start] = tmp;
}

void HeapSort(int arr[], int n) {
    for (int i = n / 2; i > 0; i--) {
        HeapAdjust(arr, i, n);
    }
    cout << n << " ";
    for (int i = 1;i <= n; i++) {
        cout << arr[i];
        if (i != n)cout << " ";
    }
    cout << endl;
    for (int i = n; i > 1; i--) {
        swap(arr[1], arr[i]);
        HeapAdjust(arr, 1, i - 1);
        cout << n << " ";
        for (int j = 1;j <= n; j++) {
            cout << arr[j];
            if (j != n)cout << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    HeapSort(arr, n);
    return 0;
}