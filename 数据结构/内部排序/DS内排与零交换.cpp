#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    int arr[n], cnt = 0, index = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 0) {
            index = i;
        }
    }
    while (arr[0] != 0) {
        if (arr[index] == 0) {
            for (int i = 0; i < n; i++) {
                if (arr[i] == index) {
                    swap(arr[i], arr[index]);
                    index = i;
                    cnt++;
                }
            }
        }
    }
    bool flag = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != i) {
            flag = 1;
            cnt++;
        }
    }
    if(flag==1)cnt++;
    cout << cnt;
    return 0;
}