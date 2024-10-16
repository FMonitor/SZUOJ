#include<bits/stdc++.h>
using namespace std;
class account {
protected:
    double balance;
    double ratio;
    int num;
    char type;
public:
    account(char t, int n, double b) : balance(b), num(n), type(t) {
        ratio = 0.5;
    }
    account(account& a) {
        type = a.type;
        balance = a.balance;
        ratio = 1.5;
        num = a.num + 50000000;
    }
    void getb() {
        balance += balance * ratio * 0.01;
        cout << "Account=" << num << "--sum=" <<balance<<endl;
    }
    void query() {
        cout << "Account=" << num << "--";
        if (type == 'P') cout << "Person";
        else cout << "Enterprise";
        cout << "--sum=" << balance << "--rate=" << ratio * 0.01 << endl;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        char c;
        int b;
        cin >> n >> c >> b;
        account L(c, n, b);
        account D(L);
        char op;
        cin >> op;
        if (op == 'C') {
            L.getb();
        } else {
            L.query();
        }
        cin >> op;
        if (op == 'C') {
            D.getb();
        } else {
            D.query();
        }
    }
    return 0;
}

