
#include<bits/stdc++.h>
using namespace std;
class CTelNumber {
private:
    char* p;
public:
    CTelNumber() {
        p = new char[8];
    }
    CTelNumber(char* arr) {
        p = new char[8];
        for (int i = 0; i < 7; i++) {
            p[i] = arr[i];
        }
    }
    CTelNumber(const CTelNumber& N) {
        p = new char[8];
        p[0] = (N.p[1] <= '4' ? '8' : '2');
        for (int i = 0; i < 7; i++) {
            p[i + 1] = N.p[i];
        }
    }
    ~CTelNumber() {
        delete[] p;
    }
    void print() {
        for (int i = 0; i < 8; i++)
            std::cout << p[i];
        std::cout << endl;
    }
    bool check() {
        if (p[0] < '2' || p[0]>'8' || strlen(p)!=7) return 1;
        for (int i = 0; i < 7; i++) {
            if (p[i] < '0' || p[i]>'9')
                return 1;
        }
        return 0;
    }
};

int main() {
    int t;
    cin >> t;
    char *n= new char[8];
    for (int i = 0; i < t; i++) {
        cin >> n;
        CTelNumber c(n);
        CTelNumber copy(c);
        if (!c.check()) {
            copy.print();
        } else {
            cout << "Illegal phone number" << endl;
        }
    }
    delete[] n;
    return 0;
}