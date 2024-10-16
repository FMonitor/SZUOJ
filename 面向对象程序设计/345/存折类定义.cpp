#include<iostream>
#include<string.h>
using namespace std;
class CAccount {
private:
    long long account;
    char name[10];
    float balance;
public:
    CAccount(long long account, char name[], float balance);
    CAccount() = default;
    // void set_account(long long account);
    // void set_name(char name[]);
    // void set_balance(float balance);
    // long long get_account();
    // char* get_name();
    // float get_balance();
    void print();
    void deposit(float money);
    void withdraw(float money);
};
CAccount::CAccount(long long account, char name[], float balance) {
    this->account = account;
    strcpy(this->name, name);
    this->balance = balance;
}
void CAccount::deposit(float balance) {
    cout << name << "'s balance is " << this->balance << endl;
    cout << "saving ok!" << endl;
    this->balance += balance;
}
void CAccount::withdraw(float balance) {
    cout << name << "'s balance is " << this->balance << endl;
    if (this->balance < balance) {
        cout << "sorry! over limit!" << endl;
    } else {
        
        cout << "withdraw ok!" << endl;
        this->balance -= balance;
    }
}
void CAccount::print() {
    cout << name << "'s balance is " << this->balance << endl;
}
int main() {
    int n;
    n = 2;
    for(int i=0; i<n; i++) {
        long long account;
        char name[10];
        float balance;
        cin >> account >> name >> balance;
        CAccount c(account, name, balance);
        float money;
        cin >> money;
        c.deposit(money);
        cin >> money;
        c.withdraw(money);
        c.print();
    }
}