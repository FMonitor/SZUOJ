#include<bits/stdc++.h>
using namespace std;
class Node2D {
protected:
    string location;
public:
    Node2D() {}
    Node2D(string l) :location(l){}
};

class Body : virtual public Node2D {
protected:
    int health;
    int defense;
public:
    Body() {}
    Body(string l, int h, int d) :Node2D(l), health(h), defense(d) {}
    
};

class Weapon : virtual public Node2D {
protected:
    string w_name;
    int damage;
public:
    Weapon() {}
    Weapon(string l, string n, int d) :Node2D(l), w_name(n), damage(d) {}
    
};

class Player : public Body, public Weapon {
    string name;
public:
    Player() {}
    Player(string l,string na, int h, int d, string wn, int dmg) :Weapon(l, wn, dmg), Body(l, h, d),Node2D(l), name(na) {}
    void attack(Player &p) {
        int dmg = (damage - p.defense);
        if (dmg > 0) {
            p.health -= dmg;
        }
        cout << name << " deal " << dmg << " damage to " << p.name << endl;
        if (p.health <= 0) {
            cout << name << " defeated " << p.name << " by " << w_name << " in " << location << endl;
        }else{
            cout << p.name << " still have " << p.health << " health\n\n";
        }
    }
    int geth(){
        return health;
    }
};

int main() {
    string location, n1, n2, w1, w2;
    int h1, h2, def1, def2, dmg1, dmg2;
    cin >> location >> n1 >> h1 >> def1 >> w1 >> dmg1;
    cin >> n2 >> h2 >> def2 >> w2 >> dmg2;
    Player p1(location, n1, h1, def1, w1, dmg1);
    Player p2(location, n2, h2, def2, w2, dmg2);
    while (p1.geth() && p2.geth()) {
        p1.attack(p2);
        if (!p2.geth()) {
            break;
        }
        p2.attack(p1);
    }
    return 0;
}