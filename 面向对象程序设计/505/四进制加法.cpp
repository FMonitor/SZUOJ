#include<bits/stdc++.h>
using namespace std;
class Four {
private:
    int n;
public:
    Four(int n) :n(n) {}
    Four operator+(const Four rhs) {
        n += rhs.n;
        int cnt = 0;
        int tmp = n;
        while (tmp) {
            cnt++;
            tmp /= 10;
        }//求数的位数

        for (int i = 1; i <= cnt; i++) {
            if (n % int(pow(10, i)) / (pow(10, i - 1)) >= 4) {
                n -= 4 * pow(10, i - 1);
                n += pow(10, i);
            }
        }//每一位进位

        return *this;
    }
    friend ostream& operator<<(ostream& out, Four f) {
        out << f.n << endl;
        return out;
    }
};
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif  
    int t;
    cin >> t;
    Four F(0);
    while (t--) {
        int n;
        cin >> n;
        Four tmp(n);
        F = F + tmp;
    }
    cout << F << endl;
}

