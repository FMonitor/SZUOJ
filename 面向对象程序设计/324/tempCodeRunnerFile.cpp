#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
struct customer {
    string name;
    string terminal;
    string op;
    string card;
    string validate;
    string number;
    string time;
    double cost;
};

void input(customer *c) {
    // cout << "!" << endl;
    cin >> (*c).name >> (*c).terminal >> (*c).op >> (*c).card >> (*c).validate >> (*c).number >> (*c).time >> (*c).cost;
    for (int i = 0; i < 8; i++) {
        (*c).number[i + 4] = '*';
    }
}
void output(customer c) {
    std::cout << "Name: " << c.name << std::endl;
    std::cout << "Terminal: " << c.terminal << " operator: " << c.op << std::endl;
    std::cout << "Card Issuers: " << c.card << " Validity: " << c.time << std::endl;
    std::cout << "CardNumber: " << c.number << std::endl;
    std::cout << "Traded: " << c.time << std::endl;
    std::cout << fixed << setprecision(2) << "Costs: $" << c.cost;
}
int main() {
    int t;
    cin >> t;
    customer c[t];
    for (int i = 0; i < t; i++) {
        input(c+i);
        
    }
    for (int i = 0; i < t; i++) {
        output(c[i]);
        if (i != t - 1) cout << endl << endl;
    }
    return 0;
}