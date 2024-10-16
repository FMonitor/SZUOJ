#include<bits/stdc++.h>
using namespace std;
template <class T> class BoundArray {
    T arr[1000];
public:
    void set(T v, int index) {
        arr[index] = v;
    }
    void print(int len) {
        for (int i = 0; i < len; i++) {
            for (int j = 0; j!=i&&j < i; j++) {
                if (arr[i] < arr[j]) {
                    swap(arr[i], arr[j]);
                }
            }
        }
        for (int i = 0; i < len;i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int search(T target,int len) {
        for (int i = 0; i < len; i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        char type;
        cin >> type >> n;
        if (type == 'C') {
            BoundArray<char> BA;
            for (int i = 0; i < n; i++) {
                char tmp;
                cin >> tmp;
                BA.set(tmp, i);
            }
            char target;
            cin >> target;
            BA.print(n);
            cout << BA.search(target,n) << endl;
        } else if (type == 'I') {
            BoundArray<int> BA;
            for (int i = 0; i < n; i++) {
                int tmp;
                cin >> tmp;
                BA.set(tmp, i);
            }
            int target;
            cin >> target;
            BA.print(n);
            cout << BA.search(target,n) << endl;
        } else if (type == 'D') {
            BoundArray<double> BA;
            for (int i = 0; i < n; i++) {
                double tmp;
                cin >> tmp;
                BA.set(tmp, i);
            }
            double target;
            cin >> target;
            BA.print(n);
            cout << BA.search(target,n) << endl;
        } 
    }
    return 0;
}