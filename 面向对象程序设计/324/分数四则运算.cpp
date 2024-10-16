#include<iostream>
using namespace std;
struct fraction {
    int a;
    int b;
};
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
void add(fraction f1, fraction f2) {
    int a = f1.a * f2.b + f2.a * f1.b;
    int b = f1.b * f2.b;
    int c = gcd(a, b);
    a /= c;
    b /= c;
    if (a * b < 0 && a>0) {
        a = -a;
        b = -b;
    }
    cout << a << "/" << b << endl;
}
void __minus(fraction f1, fraction f2) {
    int a = f1.a * f2.b - f2.a * f1.b;
    int b = f1.b * f2.b;
    int c = gcd(a, b);
    a /= c;
    b /= c;
    if (a * b < 0 && a>0) {
        a = -a;
        b = -b;
    }
    cout << a << "/" << b << endl;
}
void mul(fraction f1, fraction f2) {
    int a = f1.a * f2.a;
    int b = f1.b * f2.b;
    int c = gcd(a, b);
    a /= c;
    b /= c;
    if (a * b < 0 && a>0) {
        a = -a;
        b = -b;
    }
    cout << a << "/" << b << endl;
}
void div(fraction f1, fraction f2) {
    int a = f1.a * f2.b;
    int b = f1.b * f2.a;
    int c = gcd(a, b);
    a /= c;
    b /= c;
    if (a * b < 0 && a>0) {
        a = -a;
        b = -b;
    }
    cout << a << "/" << b << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        fraction f1, f2;
        char x;
        cin >> f1.a >> x >> f1.b >> f2.a >> x >> f2.b;
        add(f1, f2);
        __minus(f1, f2);
        mul(f1, f2);
        div(f1, f2);
        if (t != 0) cout << endl;
    }
    return 0;
}