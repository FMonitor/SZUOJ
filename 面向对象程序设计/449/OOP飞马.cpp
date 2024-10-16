#include<bits/stdc++.h>
using namespace std;
class Animal {
protected:
    int weight;
public:
    Animal(int w) : weight(w) {}
    void a_display() {
        cout << "Animal:\n";
        display();
        cout << "\n";
    }
    void display() {
        cout << "weight:" << weight << "\n";
    }
};

class Horse : virtual public Animal {
protected:
    int Distance;
public:
    Horse(int w, int d) : Animal(w), Distance(d) {}
    void h_display() {
        cout << "Horse:\n";
        display();
        cout << "distance:" << Distance << "\n\n";
    }
};

class Bird : virtual public Animal {
protected:
    int Height;
public:
    Bird(int w, int h) : Animal(w), Height(h) {}
    void b_display() {
        cout << "Bird:\n";
        display();
        cout << "Height:" << Height << "\n\n";
    }
};

class Pegasus : public Bird, public Horse {
private:
    bool state;
public:
    Pegasus(int w, int d, int h, bool s) :Bird(w, h), Horse(w, d), Animal(w), state(s) {}
    void p_display() {
        cout << "Pegasus:\n";
        display();
        cout << "distance:" << Distance << "\n";
        cout << "Height:" << Height << "\n";
    }
    void check() {
        if (state) {
            cout << "In the air?\ntrue\n";
            cout << "On land?\nfalse\n";
        } else {
            cout << "In the air?\nfalse\n";
            cout << "On land?\ntrue\n";
        }
    }
};

int main() {
    int w, d, h, s;
    cin >> w >> d >> h >> s;
    Animal a(w);
    a.a_display();
    Horse H(w, d);
    H.h_display();
    Bird b(w, h);
    b.b_display();
    Pegasus p(w, d, h, s);
    p.p_display();
    p.check();
    return 0;
}