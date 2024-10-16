#include<bits/stdc++.h>
using namespace std;

void preOrder(int i,int size,int arr[]) {
    if (i > size || arr[i]==0) {
        return;
    }
    cout << arr[i] << " ";
    preOrder(i * 2,size,arr);
    preOrder(i * 2 + 1, size, arr);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int size;
        cin >> size;
        int arr[size+1];
        for (int i = 1; i <= size; i++) {
            cin >> arr[i];
        }
        int i = 1;
        preOrder(i, size, arr);
        cout << endl;
    }
}