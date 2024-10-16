#include<bits/stdc++.h>
using namespace std;

class BaseAccount {
protected:
    string name;
    string account;
    int balance;

public:
    BaseAccount(string n, string a, int b) :name(n), account(a), balance(b) {}
    virtual void deposit(int num) {
        balance += num;
    }
    virtual void withdraw(int n) {
        if (n > balance) {
            cout << "insufficient" << endl;
        } else {
            balance -= n;
        }
    }
    virtual void display() {
        cout << name << " " << account << " Balance:" << balance << endl;
    }
    char gettype() {
        return account[1];
    }
};

class BasePlus : public BaseAccount {
protected:
    int limit = 5000;
    int limit_sum = 0;
public:
    BasePlus(string n, string a, int b) : BaseAccount(n, a, b) {}
    void deposit(int num) {
        if (limit + num <= 5000) {
            limit += num;
        } else if (limit + num > 5000) {
            limit_sum = 5000 - limit;
            limit = 5000;
            num -= limit_sum;
            balance += num;
        }
    }
    void withdraw(int n) {
        if (n > balance + limit) {
            cout << "insufficient" << endl;
            return;
        } else {
            balance -= n;
        }
        if (balance < 0) {
            limit += balance;
            balance = 0;
        }
    }
    void display() {
        cout << name << " " << account << " Balance:" << balance << " limit:" << limit << endl;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    BaseAccount** Account = new BaseAccount*[t];
    for (int i = 0; i < t; i++) {
        string name, account;
        int balance;
        cin >> name >> account >> balance;
        if (account[1] == 'A') {
            Account[i] = new BaseAccount(name, account, balance);
            int d1, w1, d2, w2;
            cin >> d1 >> w1 >> d2 >> w2;
            Account[i]->deposit(d1);
            Account[i]->withdraw(w1);
            Account[i]->deposit(d2);
            Account[i]->withdraw(w2);
            Account[i]->display();
        }
        if (account[1] == 'P') {
            Account[i] = new BasePlus(name, account, balance);
            int d1, w1, d2, w2; 
            cin >> d1 >> w1 >> d2 >> w2;
            Account[i]->deposit(d1);
            Account[i]->withdraw(w1);
            Account[i]->deposit(d2);
            Account[i]->withdraw(w2);
            Account[i]->display();
        }
    }
    // for (int i = 0; i < t; i++) {
    //     if (Account[i]->gettype() == 'A')
    //         Account[i]->display();
    // }
    // for (int i = 0; i < t; i++) {
    //     if (Account[i]->gettype() == 'P')
    //         Account[i]->display();
    // }
    for (int i = 0; i < t; i++) {
        delete Account[i];
    }
    delete[] Account;
    return 0;
}