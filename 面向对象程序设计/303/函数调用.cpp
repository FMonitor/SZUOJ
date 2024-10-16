#include<bits/stdc++.h>
using namespace std;
int __pow(int n) {
    return n * n;
}
double __sqrt(double n) {
    return sqrt(n);
}
string __uppercase(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 32;
        }
    }
    return s;
}
int main() {
    int t;
    cin >> t;
    int (*ppow)(int) = __pow;
    double (*psqrt)(double) = __sqrt;
    string(*puppercase)(string) = __uppercase;
    while (t--) {
        char type;
        cin >> type;
        if (type == 'S') {
            string str;
            cin >> str;
            str = (*puppercase)(str);
            cout << str << endl;
        } else if (type == 'I') {
            int n;
            cin >> n;
            cout << (*ppow)(n) << endl;
        } else if (type == 'F') {
            double n;
            cin >> n;
            cout << (*psqrt)(n) << endl;
        }
    }
    return 0;
}