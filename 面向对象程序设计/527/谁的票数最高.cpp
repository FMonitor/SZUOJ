#include<bits/stdc++.h>
using namespace std;
template <class T>
void calculate(T* arr, int len, T& res, int& cnt) {
    sort(arr, arr + len);
    int now = 1;
    T ans = arr[0];
    for (int i = 1; i < len; i++) {
        if (arr[i - 1] == arr[i]) {
            now++;
        } else {
            if (now > cnt) {
                cnt = now;
                res = ans;
            }
            now = 1;
            ans = arr[i];
        }
    }
    if (now > cnt) {
        cnt = now;
        res = ans;
    }
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        char type;
        cin >> type >> n;
        if (type == 'C') {
            char res = '0';
            int cnt = 0;
            char arr[n];
            for (int i = 0;i < n; i++) {
                cin >> arr[i];
            }
            calculate(arr, n, res, cnt);
            cout << res << " " << cnt << endl;
        } else if (type == 'I') {
            int res = '0';
            int cnt = 0;
            int arr[n];
            for (int i = 0;i < n; i++) {
                cin >> arr[i];
            }
            calculate(arr, n, res, cnt);
            cout << res << " " << cnt << endl;
        } else if (type == 'D') {
            double res = '0';
            int cnt = 0;
            double arr[n];
            for (int i = 0;i < n; i++) {
                cin >> arr[i];
            }
            calculate(arr, n, res, cnt);
            cout << res << " " << cnt << endl;
        } else if (type == 'S') {
            string res = "0";
            int cnt = 0;
            string arr[n];
            for (int i = 0;i < n; i++) {
                cin >> arr[i];
            }
            calculate(arr, n, res, cnt);
            cout << res << " " << cnt << endl;
        }
    }
    return 0;
}

