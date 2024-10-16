#include<bits/stdc++.h>
using namespace std;
class Vehicle {
protected:
    string no;
public:
    Vehicle(string n) : no(n) {}
    virtual void display() = 0;
};

class Car : public Vehicle {
private:
    int num;
    int weight;
public:
    Car(int n, int w, string no) : Vehicle(no), num(n), weight(w) {}
    void display() {
        cout << no << " " << num * 8 + weight * 2 << endl;
    }
};

class Truck : public Vehicle {
private:
    int weight;
public:
    Truck(int w, string no) : Vehicle(no), weight(w) {}
    void display() {
        cout << no << " " << weight * 5 << endl;
    }
};

class Bus : public Vehicle {
private:
    int num;
public:
    Bus(int n, string no) : Vehicle(no), num(n) {}
    void display() {
        cout << no << " " << num * 3 << endl;
    }
};

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    #endif
    Vehicle* pv;
    int t;
    cin >> t;
    while (t--) {
        int type;
        cin >> type;
        if (type == 1) {
            string no;
            int num, weight;
            cin >> no >> num >> weight;
            pv = new Car(num, weight, no);
            pv->display();
            delete pv;
        } else if (type == 2) {
            string no;
            int weight;
            cin >> no >> weight;
            pv = new Truck(weight, no);
            pv->display();
            delete pv;
        } else if (type == 3) {
            string no;
            int num;
            cin >> no >> num;
            pv = new Bus(num, no);
            pv->display();
            delete pv;
        }
    }
    return 0;
}