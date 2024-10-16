#include<bits/stdc++.h>
using namespace std;

class Customer {
private:
    static int TotalCustNum;
    static int Rent;
    static int Year;
    int CustID;
    char* CustName;
public:
    Customer(char* name);
    ~Customer();
    static void changeYear(int r);
    void Display();
};
int Customer::TotalCustNum = 0;
int Customer::Rent = 0;
int Customer::Year = 0;
Customer::Customer(char* n) {
    TotalCustNum++;
    Rent += 150;
    CustName = new char[strlen(n)];
    for (int i = 0; i < strlen(n); i++) {
        CustName[i] = n[i];
    }
    CustID = Year * 10000 + TotalCustNum;
}
Customer::~Customer() {
    delete[] CustName;
}
void Customer::changeYear(int r) {
    Year = r;
}
void Customer::Display() {
    cout << CustName << " " << CustID << " " << Customer::TotalCustNum << " " << Customer::Rent;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int y;
        char s[10];
        cin >> y;
        Customer::changeYear(y);
        bool flag = 0;
        while (cin >> s) {
            if (strlen(s)==1 && s[0]=='0') break;
            if (flag == 0) {
                flag = 1;
            } else {
                cout << endl;
            }
            Customer* c = new Customer(s);
            c->Display();
        }
        if (t != 0) cout << endl;
    }
    return 0;
}
