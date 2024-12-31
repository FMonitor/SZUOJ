#include<bits/stdc++.h>
using namespace std;

int n;
string str[100];
void merge(string str[], int l, int mid, int r) {
    string nStr[r - l + 1];
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (str[i] >= str[j]) {
            nStr[k++] = str[i++];
        } else {
            nStr[k++] = str[j++];
        }
    }while (i <= mid) {
        nStr[k++] = str[i++];
    }while (j <= r) {
        nStr[k++] = str[j++];
    }
    k = 0;
    for (int i = l;i <= r; i++) {
        str[i] = nStr[k++];
    }
}

void mergeSort(string str[]) {

    for (int len = 1; len < n; len *= 2) {
        for (int l = 0; l < n - len; l += 2 * len) {
            int mid = len + l - 1;
            int r = min(l + 2 * len - 1, n - 1);
            merge(str, l, mid, r);
        }for (int i = 0; i < n; i++) {
            cout << str[i];
            if (i != n-1)cout << " ";
        }
        cout << endl;
    }

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> str[i];
        }
        mergeSort(str);
        if (t != 0)cout << endl;
    }
    return 0;
}