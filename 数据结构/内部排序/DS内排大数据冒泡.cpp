#include<iostream>
using namespace std;
int arr[5100];
int bubbleSort(int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j + 1]);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    
    int n=1;
    while (cin >>n) {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << bubbleSort(n) << endl;
    }
    return 0;
    
}