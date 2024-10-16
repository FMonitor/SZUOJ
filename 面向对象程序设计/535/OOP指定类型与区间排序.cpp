#include<bits/stdc++.h>
using namespace std;
template <class T>
void mysort(T* arr, int beg, int end) {
    sort(arr + beg, arr + end);
}
int main() {
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string type;
        cin >> type >> n;
        if (type == "string") {
            string arr[n];
            string tmp;
            cin >> tmp;
            int i = 1;
            bool flag = 0;
            int beg = 0, end = 0;
            for (i; i < tmp.size(); i++) {
                if (tmp[i] == '-') {
                    flag = 1;
                    continue;
                }
                if (tmp[i] == ',') {
                    if (flag) beg *= -1;
                    i++;
                    break;
                }
                beg *= 10;
                beg += tmp[i] - '0';
            }
            flag = 0;
            for (i;i < tmp.size();i++) {
                if (tmp[i] == '-') {
                    flag = 1;
                    continue;
                }
                if (tmp[i] == ')')break;
                end *= 10;
                end += tmp[i] - '0';
            }
            if (flag) {
                end *= -1;
            }
            beg = beg < 0 ? 0 : beg;
            end = end > n ? n : end;
            end = end < 0 ? 0 : end;
            // beg = beg < n ? beg : n - 1;
            cin >> tmp;
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            if (beg < end && beg<n)
                mysort(arr, beg, end);
            cout << "[";
            for (int i = 0; i < n; i++) {
                cout <<fixed<<setprecision(1)<< arr[i];
                if (i != n - 1) {
                    cout << ", ";
                }
            }
            cout << "]\n";
        } else if (type == "int") {
            int arr[n];
            string tmp;
            cin >> tmp;
            int i = 1;
            bool flag = 0;
            int beg = 0, end = 0;
            for (i; i < tmp.size(); i++) {
                if (tmp[i] == '-') {
                    flag = 1;
                    continue;
                }
                if (tmp[i] == ',') {
                    if (flag) beg *= -1;
                    i++;
                    break;
                }
                beg *= 10;
                beg += tmp[i] - '0';
            }
            flag = 0;
            for (i;i < tmp.size();i++) {
                if (tmp[i] == '-') {
                    flag = 1;
                    continue;
                }
                if (tmp[i] == ')')break;
                end *= 10;
                end += tmp[i] - '0';
            }
            if (flag) {
                end *= -1;
            }
            beg = beg < 0 ? 0 : beg;
            end = end > n ? n : end;
            end = end < 0 ? 0 : end;
            // beg = beg < n ? beg : n - 1;
            cin >> tmp;
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            if (beg < end && beg<n)
                mysort(arr, beg, end);
            cout << "[";
            for (int i = 0; i < n; i++) {
                cout <<fixed<<setprecision(1)<< arr[i];
                if (i != n - 1) {
                    cout << ", ";
                }
            }
            cout << "]\n";
        } else if (type == "float") {
            double arr[n];
            string tmp;
            cin >> tmp;
            int i = 1;
            bool flag = 0;
            int beg = 0, end = 0;
            for (i; i < tmp.size(); i++) {
                if (tmp[i] == '-') {
                    flag = 1;
                    continue;
                }
                if (tmp[i] == ',') {
                    if (flag) beg *= -1;
                    i++;
                    break;
                }
                beg *= 10;
                beg += tmp[i] - '0';
            }
            flag = 0;
            for (i;i < tmp.size();i++) {
                if (tmp[i] == '-') {
                    flag = 1;
                    continue;
                }
                if (tmp[i] == ')')break;
                end *= 10;
                end += tmp[i] - '0';
            }
            if (flag) {
                end *= -1;
            }
            beg = beg < 0 ? 0 : beg;
            end = end > n ? n : end;
            end = end < 0 ? 0 : end;
            // beg = beg < n ? beg : n - 1;
            cin >> tmp;
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            if (beg < end && beg<n)
                mysort(arr, beg, end);
            cout << "[";
            for (int i = 0; i < n; i++) {
                cout <<fixed<<setprecision(1)<< arr[i];
                if (i != n - 1) {
                    cout << ", ";
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}

