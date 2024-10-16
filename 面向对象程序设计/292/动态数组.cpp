#include<iostream>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        char type;
        int n;
        cin >> type >> n;
        if (type == 'I') {
            int* p = new int[n];
            double* sum = new double;
            for (int i = 0; i < n; i++) {
                cin >> *(p + i);
                *sum += *(p + i);
            }
            cout << *sum / n << endl;
        } else if (type == 'C') {
            char* ch = new char[n];
            char* ans = new char;
            for (int i = 0;i < n; i++) {
                cin >> *(ch + i);
            }
            *ans = *ch;
            for (int i = 1; i < n; i++) {
                *ans = max(*ans, *(ch + i));
            }
            cout << *ans << endl;


                } else if (type == 'F') {
                    double* p = new double[n];
                    for (int i = 0; i < n; i++) {
                        cin >> *(p + i);
                    }
                    sort(p, p + n);
                    cout << *p << endl;
                }
    }
    return 0;
}