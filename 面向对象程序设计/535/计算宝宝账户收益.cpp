/********** Write your code here! **********/
#include<bits/stdc++.h>
using namespace std;
class CPeople {
protected:
    string id;
    string name;
public:
    CPeople(string i, string n) :id(i), name(n) {}
    CPeople() {}
};

class CInternetUser : virtual public CPeople {
protected:
    string pwd;
public:
    CInternetUser() {}
    CInternetUser(string n, string i, string p) :CPeople(i, n), pwd(p) {}
    bool login(string i, string p) {
        return id == i && pwd == p;
    }
    void registerUser(string n, string i, string p) {
        name = n;
        id = i;
        pwd = p;
    }
};

class CBankCustomer : virtual public CPeople {
protected:
    double balance;
public:
    CBankCustomer(string n, string i, double b) :CPeople(i, n), balance(b) {}
    CBankCustomer() {
        balance = 0;
    }
    void setBalance(double b) {
        balance = b;
    }

    void openAccount(string n, string i) {
        id = i;
        name = n;
    }
    void deposit(double b) {
        balance += b;
    }
    bool withdraw(double b) {
        if (balance < b) {
            return false;
        } else {
            balance -= b;
            return true;
        }
    }
};

class CInternetBankCustomer :public CBankCustomer, public CInternetUser {
private:
    double _balance;
    double balance_old;
    double day_profit;
    double profit10k;
    double profit10k_old;
    double gain;
public:
    CInternetBankCustomer() {
        _balance = 0;
        balance_old = 0;
        day_profit = 0;
        profit10k = 0;
        profit10k_old = 0;
        gain = 0;
    }
    void setInterest(double p) {
        profit10k = p / 10000;
    }
    void calculateProfit() {
        day_profit = balance_old * profit10k_old;
        _balance += day_profit;
    }
    void print() {
        cout << "Name: " << name << " ID: " << id << endl;
        cout << "Bank balance: " << balance << endl;
        cout << "Internet bank balance: " << _balance << endl;
        cout << endl;
        balance_old = _balance;
        profit10k_old = profit10k;
    }
    bool deposit(double b) {
        if (balance < b) {
            return false;
        }
        balance -= b;
        _balance += b;
        return true;
    }
    bool withdraw(double b) {
        if (_balance < b) {
            return false;
        }
        _balance -= b;
        balance += b;
        return true;
    }
};
