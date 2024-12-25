#include<iostream>
#include<algorithm>
using namespace std;
int n, m, a[1005];
string s;
int find(int x) {
    for (int i = 1;i <= n;i++) {
        if (a[i] == x)
            return i;
    }
    return -1;
}
int main() {
    cin >> n >> m;
    int k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        k = i;
        while (k > 1 && a[k] < a[k / 2]) {
            swap(a[k], a[k / 2]);
            k /= 2;
        }
    }
    int x1, x2;
    while (m--) {
        cin >> x1;
        cin >> s;
        if (s == "and") {
            cin >> x2;
            cin >> s;
            cin >> s;
            if (find(x1) / 2 == find(x2) / 2)
                cout << "T" << endl;
            else
                cout << "F" << endl;
        } else {
            cin >> s;
            if (s == "a") {
                cin >> s;
                cin >> s;
                cin >> x2;
                if (find(x1) / 2 == find(x2))
                    cout << "T" << endl;
                else
                    cout << "F" << endl;
            } else {
                cin >> s;
                if (s == "root") {
                    if (find(x1) == 1)
                        cout << "T" << endl;
                    else
                        cout << "F" << endl;
                } else {
                    cin >> s;
                    cin >> x2;
                    if (find(x2) / 2 == find(x1))
                        cout << "T" << endl;
                    else
                        cout << "F" << endl;
                }
            }
        }
    }
    return 0;
}