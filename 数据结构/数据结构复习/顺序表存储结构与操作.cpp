#include<bits/stdc++.h>
using namespace std;

void insert(int arr[], int num, int pos, int& n) {
    if (pos > n + 1) {
        cout << "error" << endl;
        return;
    }
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = num;
    n++;
    cout << n <<" ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void erase(int arr[], int pos, int n) {
    if (pos > n || pos <1) {
        cout << "error" << endl;
        return;
    }
    n--;
    for (int i = pos - 1; i < n; i++) {
        arr[i] = arr[i + 1];
    }
    cout << n << " ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void query(int arr[], int pos, int n) {
    if (pos > n || pos<1) {
        cout << "error" ;
        return;
    }
    cout << arr[pos-1];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int arr[1000];
    int n;
    cin >> n;
    cout << n << " ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cout << arr[i]<<" ";
    }
    cout << endl;
    int pos, num;
    for (int i = 0; i < 2; i++) {
        cin >> pos >> num;
        insert(arr, num, pos,n);
    }
    for (int i = 0; i < 2; i++) {
        cin >> pos ;
        erase(arr, pos, n);
    }
    for (int i = 0; i < 2; i++) {
        cin >> pos;
        query(arr,pos, n);
        if (i != 1)cout << endl;
    }
    return 0;
}