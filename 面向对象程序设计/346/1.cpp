#include<iostream>
#include<string.h>
using namespace std;
class CAccount {
private:
    long long account;
    char name[10];
    float balance;
public:
    CAccount(long long account, char name[], float balance) {
        this->account = account;
        strcpy(this->name, name);
        this->balance = balance;
    }
    void deposit(float balance) {
        cout << name << "'s balance is " << this->balance << endl;
        cout << "saving ok!" << endl;
        this->balance += balance;
    }
    void withdraw(float balance) {
        cout << name << "'s balance is " << this->balance << endl;
        if (this->balance < balance) {
            cout << "sorry! over limit!" << endl;
        } else {

            cout << "withdraw ok!" << endl;
            this->balance -= balance;
        }
    }
    void print() {
        cout << name << "'s balance is " << this->balance << endl;
    }
};

int main() {
    long long account;
    char name[10];
    float balance;

    cin >> account >> name >> balance;
    CAccount c1(account, name, balance);
    float money;
    cin >> money;
    c1.deposit(money);
    cin >> money;
    c1.withdraw(money);
    c1.print();

    cin >> account >> name >> balance;
    CAccount c2(account, name, balance);
    float money;
    cin >> money;
    c2.deposit(money);
    cin >> money;
    c2.withdraw(money);
    c2.print();
    return 0;
}