#include<bits/stdc++.h>
using namespace std;
class Complex {
private:
    int real, imag;
public: 
    Complex(int r, int i) : real(r), imag(i) {}
    Complex operator+(const Complex &c) {
        return Complex(real + c.real, imag + c.imag);
    }
    Complex operator-(const Complex &c) {
        return Complex(real - c.real, imag - c.imag);
    }
    Complex operator*(const Complex &c) {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }
    void print() {
        std::cout <<"Real="<< real << " Image=" << imag << std::endl;
    }
};

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    Complex c1(a, b), c2(c, d);
    Complex c3 = c1 + c2;
    c3.print();
    c3 = c1 - c2;
    c3.print();
    c3 = c1 * c2;
    c3.print();
    return 0;
}