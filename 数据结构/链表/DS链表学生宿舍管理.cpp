#include<bits/stdc++.h>
#include<list>
using namespace std;
struct Dorm {
    string name;
    int id;
    Dorm(string name, int id) : name(name), id(id) {}
    Dorm() {}
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int n, m;
    list<Dorm> used_dorm;
    list<Dorm> free_dorm;
    for (int i = 101;i <= 120;i++) {
        free_dorm.push_back(Dorm("", i));
    }
    cin >> n;
    int index = 101;
    while (n--) {
        Dorm tmp;
        cin >> tmp.name >> tmp.id;
        used_dorm.push_back(tmp);
        for(auto it = free_dorm.begin();it != free_dorm.end();it++) {
            if (it->id == tmp.id) {
                free_dorm.erase(it);
                break;
            }
        }
    }
    cin >> m;
    while (m--) {
        string op;
        cin >> op;
        if (op == "assign") {
            cin >> op;
            Dorm tmp = free_dorm.front();
            for (auto it = used_dorm.begin();it != used_dorm.end();it++) {
                if (it->id > tmp.id) {
                    used_dorm.insert(it, Dorm(op, tmp.id));
                    free_dorm.pop_front();
                    break;
                }
            }
        } else if (op == "return") {
            int room;
            cin >> room;
            for (auto it = used_dorm.begin();it != used_dorm.end();it++) {
                if (it->id == room) {
                    used_dorm.erase(it);
                    free_dorm.push_back(Dorm("", room));
                    break;
                }
            }
        } else if (op == "display_used") {
            auto it = used_dorm.begin();
            cout << it->name << "(" << it->id << ")";
            it++;
            for (it;it != used_dorm.end();it++) {
                cout << "-" << it->name << "(" << it->id << ")";
            }
            cout << endl;
        } else {
            auto it2 = free_dorm.begin();
            cout << it2->id;
            it2++;
            for (it2;it2 != free_dorm.end();it2++) {
                cout << "-" << it2->id;
            }cout << endl;
        }
    }


    return 0;
}