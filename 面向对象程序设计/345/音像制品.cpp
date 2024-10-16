#include<bits/stdc++.h>
using namespace std;
class product {
private:
    string type;
    string name;
    int price;
    bool status;
public:
    product(string& type, string& name, int& price, bool& status);
    product() = default;
    void print();
    void set_type(string& type);
    void set_name(string& name);
    void set_price(int& price);
    void set_status(bool& status);
    string get_type();
    string get_name();
    int get_price();
    bool get_status();
    int get_fee(int day);
};
product::product(string& type, string& name, int& price, bool& status) {
    this->type = type;
    this->name = name;
    this->price = price;
    this->status = status;
}
void product::print() {
    cout << type << " " << name << " " << price << " " << status << endl;
}
void product::set_type(string& type) {
    this->type = type;
}
void product::set_name(string& name) {
    this->name = name;
}
void product::set_price(int& price) {
    this->price = price;
}
void product::set_status(bool& status) {
    this->status = status;
}
string product::get_type() {
    return type;
}
string product::get_name() {
    return name;
}
int product::get_price() {
    return price;
}
bool product::get_status() {
    return status;
}
int product::get_fee(int day) {
    return price * day;
}
int main() {
    int n;
    cin >> n;
    product p[n];
    for (int i = 0; i < n; i++) {
        int t;
        string type, name;
        int price;
        bool status;
        string output_s;
        cin >> t >> name >> price >> status;
        if (t == 1) {
            type = "BF";
        } else if (t == 2) {
            type = "CD";
        } else if (t == 3) {
            type = "VCD";
        } else if (t == 4) {
            type = "DVD";
        }
        p[i] = product(type, name, price, status);
        int op;
        cin >> op;
        if (op == 0) {
            
            cout <<p[i].get_type()<< "[" << p[i].get_name()  << "]";
            if (p[i].get_status()) {
                cout << "rented" << endl;
            } else {
                cout << "not rented" << endl;
            }
        } else {
           cout <<p[i].get_type()<< "[" << p[i].get_name()  << "]";
            if (p[i].get_status()) {
                cout << "rented" << endl;
            } else {
                cout << "not rented" << endl;
            }
            if (p[i].get_status()) {
                printf("Rental: %d\n", p[i].get_fee(op));
            } else {
                printf("No rental\n");
            }
        }
    }
    return 0;
}