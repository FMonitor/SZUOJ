#include<bits/stdc++.h>
using namespace std;
class robot {
protected:
    string name;
    int hp;
    int dmg;
    int def;
    char type;
    int lvl;
public:
    robot() {}
    robot(string n, char t, int l) :name(n), type(t), lvl(l) {
        if (t == 'N') {
            hp = 5 * lvl;
            dmg = 5 * lvl;
            def = 5 * lvl;
        } else if (t == 'A') {
            hp = 5 * lvl;
            dmg = 10 * lvl;
            def = 5 * lvl;
        } else if (t == 'D') {
            hp = 5 * lvl;
            dmg = 5 * lvl;
            def = 10 * lvl;
        } else if (t == 'H') {
            hp = 50 * lvl;
            dmg = 5 * lvl;
            def = 5 * lvl;
        }
    }
    void print() {
        cout << name << "--" << type << "--" << lvl << "--" << hp << "--" << dmg << "--" << def << endl;
    }
    void setName(string n) {
        name = n;
    }
    bool setType(char t) {
        if (t == type)
            return false;
        type = t;
        if (t == 'N') {
            hp = 5 * lvl;
            dmg = 5 * lvl;
            def = 5 * lvl;
        } else if (t == 'A') {
            hp = 5 * lvl;
            dmg = 10 * lvl;
            def = 5 * lvl;
        } else if (t == 'D') {
            hp = 5 * lvl;
            dmg = 5 * lvl;
            def = 10 * lvl;
        } else if (t == 'H') {
            hp = 50 * lvl;
            dmg = 5 * lvl;
            def = 5 * lvl;
        } else {
            return false;
        }
        return true;
    }
    void setLvl(int n) {
        lvl = n;
    }
    string getName() {
        return name;
    }
    int getHp() {
        return hp;
    }
    int getDmg() {
        return dmg;
    }
    int getDef() {
        return def;
    }
};

bool trans(robot &a, char &ty) {
    if (a.setType(ty))
        return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    while (n--) {
        string name;
        char t;
        int lvl;
        cin >> name >> t >> lvl;
        robot a(name, t, lvl);
        char tra;
        cin >> tra;
        if (trans(a, tra)) {
            cnt++;
        }
        a.print();
    }
    cout << "The number of robot transform is " << cnt << endl;
    return 0;
}