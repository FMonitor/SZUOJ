#include<bits/stdc++.h>
using namespace std;
class CAccount {
protected:
    long long account;
    char name[10];
    double balance;
public:
    CAccount(long long a, char* n, double b) :account(a), balance(b) {
        strcpy(name, n);
    }
    void check() {
        cout << "balance is " << balance << endl;
    }
    void deposit(double money) {
        balance += money;
        cout << "saving ok!" << endl;
        check();
    }
    void withdraw(double money) {
        if(balance < money) {
            cout << "sorry! over !" << endl;
            check();
            return;
        }
        balance -= money;
        cout << "withdraw ok!" << endl;
        check();
    }
};

class CCreditCard : public CAccount {
protected:
    double limit;
public:
    CCreditCard(long long a, char* n, double b, double l) :CAccount(a, n, b), limit(l) {}
    void withdraw(double money) {
        if(balance + limit < money) {
            cout << "sorry! over balance!" << endl;
            check();
            return;
        }
        balance -= money;
        cout << "withdraw ok!" << endl;
        check();
    }
};

int main() {
    long long id1, id2;
    int b1, b2, cre;
    int m1, m2, m3, m4;
    char n1[10], n2[10];
    cin >> id1 >> n1 >> b1 >> m1 >> m2;
    cin >> id2 >> n2 >> b2 >> cre >> m3 >> m4;
    CAccount a(id1, n1, b1);
    CCreditCard c(id2, n2, b2, cre);
    a.check();
    a.deposit(m1);
    a.withdraw(m2);
    c.check();
    c.deposit(m3);
    c.withdraw(m4);
    return 0;
}