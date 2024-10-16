//补齐头文件 及要求的类
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


/*******************************************/
int main() {
    int t, no_of_days, i;
    string i_xm, i_id, i_mm, b_xm, b_id, ib_id, ib_mm;
    double money, interest;
    char op_code;

    // 输入测试案例数t
    cin >> t;
    while (t--) {
        // 输入互联网用户注册时的用户名,id,登陆密码
        cin >> i_xm >> i_id >> i_mm;

        // 输入银行开户用户名,id
        cin >> b_xm >> b_id;

        // 输入互联网用户登陆时的id,登陆密码
        cin >> ib_id >> ib_mm;

        CInternetBankCustomer ib_user;

        ib_user.registerUser(i_xm, i_id, i_mm);
        ib_user.openAccount(b_xm, b_id);

        if (ib_user.login(ib_id, ib_mm) == 0) // 互联网用户登陆,若id与密码不符;以及银行开户姓名和id与互联网开户姓名和id不同
        {
            cout << "Password or ID incorrect" << endl;
            continue;
        }

        // 输入天数
        cin >> no_of_days;
        for (i = 0; i < no_of_days; i++) {
            // 输入操作代码, 金额, 当日万元收益
            cin >> op_code >> money >> interest;
            switch (op_code) {
            case 'S': // 从银行向互联网金融帐户存入
            case 's':
                if (ib_user.deposit(money) == 0) {
                    cout << "Bank balance not enough" << endl;
                    continue;
                }
                break;
            case 'T': // 从互联网金融转入银行帐户
            case 't':
                if (ib_user.withdraw(money) == 0) {
                    cout << "Internet bank balance not enough" << endl;
                    continue;
                }
                break;
            case 'D': // 直接向银行帐户存款
            case 'd':
                ib_user.CBankCustomer::deposit(money);
                break;
            case 'W': // 直接从银行帐户取款
            case 'w':
                if (ib_user.CBankCustomer::withdraw(money) == 0) {
                    cout << "Bank balance not enough" << endl;
                    continue;
                }
                break;
            default:
                cout << "Illegal input" << endl;
                continue;
            }
            ib_user.setInterest(interest);
            ib_user.calculateProfit();
            // 输出用户名,id
            // 输出银行余额
            // 输出互联网金融账户余额
            ib_user.print();
        }
    }
}
