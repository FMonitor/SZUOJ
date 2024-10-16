#include<bits/stdc++.h>
using namespace std;
class ccomplex {
private:
    double real;
    double imag;
public:
    ccomplex() = default;
    ccomplex(double r, double i) : real(r), imag(i) {}
    friend ccomplex addCom(ccomplex c1, ccomplex c2);
    friend void outCom(ccomplex c);
};
ccomplex addCom(ccomplex c1, ccomplex c2) {
    return ccomplex(c1.real + c2.real, c1.imag + c2.imag);
}
void outCom(ccomplex c) {
    cout << "(" << c.real << "," << c.imag << ")" << endl;
}

int main() {
    int r1, i1;
    cin >> r1 >> i1;
    ccomplex c1(r1, i1);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char op;
        int r2, i2;
        cin >> op >> r2 >> i2;
        if (op == '+') {
            ccomplex            c2(r2, i2);
            c1 = addCom(c1, c2);
        } else {
            ccomplex c2(-r2, -i2);
            c1 = addCom(c1, c2);
        }
        outCom(c1);
    }
    return 0;
}