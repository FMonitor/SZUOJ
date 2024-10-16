#include<bits/stdc++.h>
using namespace std;
class Poly {
private:
    int len;
    int num[1000];
public:
    Poly() {
        len = 1;
        memset(num, 0, sizeof(num));
    }
    friend istream& operator>>(istream& is, Poly& p) {
        int n;
        is >> n;
        for (int i = 0; i < n; i++) {
            int a, b;
            is >> a >> b;
            p.num[b] = a;
            p.len = max(p.len, b) + 1;
        }
        return is;
    }
    friend ostream& operator<<(ostream& os, const Poly& p) {
        bool flag1 = 0;
        bool flag2 = 0;
        for (int i = 0; i < p.len; i++) {
            if (p.num[i] == 0) continue;
            flag1 = 1;
            if (i == 0) {
                os << p.num[i];
                flag2 = 1;
                continue;
            }
            if(flag2)
            if (p.num[i] > 0) {
                os << "+";
            }
            flag2 = 1;
            if (p.num[i] == 1) {
                os << "x";
            } else if (p.num[i] == -1) {
                os << "-x";
            } else
                os << p.num[i] << "x";
            if (i > 1) {
                os << "^" << i;
            }
        }
        if (!flag1) cout << 0; 
        return os;
    }
    Poly operator+(const Poly& p) {
        Poly res;
        res.len = max(len, p.len);
        for (int i = 0; i < res.len; i++) {
            res.num[i] = p.num[i] + num[i];
        }
        return res;
    }
    Poly operator-(const Poly& p) {
        Poly res;
        res.len = max(len, p.len);
        for (int i = 0; i < res.len; i++) {
            res.num[i] = num[i] - p.num[i];
        }
        return res;
    }
    Poly operator*(const Poly& p) {
        Poly res;
        res.len = len + p.len - 1;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < p.len; j++) {
                res.num[i + j] += num[i] * p.num[j];
            }
        }
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        Poly a, b;
        cin >> a >> b;
        cout << a + b << endl;
        cout << a - b << endl;
        cout << a * b << endl;
    }
    return 0;
}