#include<bits/stdc++.h>
using namespace std;
class phone {
protected:
    int num;
    char type;//A政府B企业C个人
public:
    phone() {}
    phone(int n, char t) :num(n), type(t) {
        cout << n << " constructed." << endl;
    }
    ~phone() {
        cout << num << " destructed." << endl;
    }
    void setn(int n) {
        num = n;
    }
    void sett(char t) {
        type = t;
    }
    int getn() {
        return num;
    }
    char gett() {
        return type;
    }
};

class vph {
private:
    phone p;
    int status;
    string name;
public:
    vph() {}
    vph(int n, char t, int s, string na) :p(n, t), status(s), name(na) {}
    void print() {
        cout << "Phone=" << p.getn() << "--Type=" << p.gett() << "--State=";
        if (status) {
            cout << "use--Owner=" << name << endl;
        } else {
            cout << "unuse--Owner=" << name << endl;
        }
    }
    int getn() {
        return p.getn();
    }
    bool check(int n) {
        if (n == p.getn())
            return true;
        return false;
    }
};

int main() {
    freopen("out.txt", "w", stdout);
    int num, state;
    char type;
    string name;
    cin >> num >> type >> state >> name;
    vph tmp1(num, type, state, name);
    cin >> num >> type >> state >> name;
    vph tmp2(num, type, state, name);
    cin >> num >> type >> state >> name;
    vph tmp3(num, type, state, name);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == tmp1.getn()) {
            tmp1.print();
        } else if (tmp == tmp2.getn()) {
            tmp2.print();
        } else if (tmp == tmp3.getn()) {
            tmp3.print();
        } else {
            cout << "wrong number.\n";
        }
    }
    return 0;
}