#include<bits/stdc++.h>
using namespace std;
class Cplx {
private:
    int a;
    int b;
public:
    Cplx();
    Cplx(int a, int b);
    Cplx add(Cplx);
    Cplx minus(Cplx);
    void print();
};
Cplx::Cplx() {
    a = 1;
    b = 1;
}
Cplx::Cplx(int a, int b) {
    this->a = a;
    this->b = b;
}
Cplx Cplx::add(Cplx rd) {
    Cplx tmp(a,b);
    tmp.a += rd.a;
    tmp.b += rd.b;
    return tmp;
}
Cplx Cplx::minus(Cplx rd) {
    Cplx tmp(a,b);
    tmp.a -= rd.a;
    tmp.b -= rd.b;
    return tmp;
}
void Cplx::print() {
    if (a != 0) {
        cout << a;
    }
    if (a != 0 && b == 0) {
        cout << endl;
    }
    bool flag = 0;
    if (a == 0 && b != 0) {
        flag = 1;
    }
    if (b > 0 && b != 1) {
        if (!flag) cout << '+';
        cout << b << 'i' << endl;
    } else if (b < 0) {
        cout << b << "i" << endl;
    } else if (b == 1&&a==0) {
        cout << 'i' << endl;
    } else if (b == 1 && a != 0) {
        cout << "+i" << endl;
    }
    if (a == 0 && b == 0) {
        cout << 0 << endl;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        Cplx c1(a, b);
        Cplx c2(c, d);
        Cplx tmp = c1.add(c2);
        cout << "sum:";
        tmp.print();
        tmp = c1.minus(c2);
        cout << "remainder:";
        tmp.print();
    }
    return 0;
}