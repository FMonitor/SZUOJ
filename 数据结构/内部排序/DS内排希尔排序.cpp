#include<iostream>
using namespace std;
int arr[1000];
void shellSort(int n) {
    int gap = n / 2;
    while (gap != 0) {
        int i, j, tmp;
        for (i = 1; i <= n; i++) {
            tmp = arr[i];
            for (j = i;j > 0;j -= gap) {
                if (j - gap < 1)break;
                if (arr[j - gap] < tmp) {
                    arr[j] = arr[j - gap];
                } else {
                    break;
                }
            }
            arr[j] = tmp;
        }
        gap /= 2;
        for (int j = 1; j <= n; j++) {
            cout << arr[j];
            if (j != n)cout << " ";
        }
        cout << endl;
    }

}

// void Shellinsert(int r[], int m, int gap) {
//     // 假设关键字为整型，放在向量r[]中
//     int n, j, temp;
//     for (n = 1; n < m; n++) {
//         temp = r[n];
//         for (j = n; j > 0; j = j - gap)  //从后向前顺序比较，并依次后移
//             if (temp < r[j - gap]) r[j] = r[j - gap];
//             else break;
//         r[j] = temp;
//     }
//     for (int j = 0; j < m; j++) {
//         cout << r[j];
//         if (j != m - 1)cout << " ";
//     }
//     cout << endl;
// }


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        shellSort(n);
        if (t != 0)cout << endl;
    }
    return 0;
}