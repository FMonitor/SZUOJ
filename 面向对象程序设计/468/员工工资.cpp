#include<bits/stdc++.h>
using namespace std;

class Employee {
protected:
    string name;
    string job;
    int lvl;
    int time;
public:
    Employee(string n, string j, int l, int t) {
        if (j != "Employee" && j != "Teamleader" && j != "Manager") {
            job = "-1";
        } else {
            job = j;
        }
        name = n;
        if (l < 0)
            lvl = -1;
        else
            lvl = l;
        if (t < 0)
            time = -1;
        else
            time = t;
    }
    virtual void salary() {
        if (job == "-1") {
            cout << "error position." << endl;
        } else if (time == -1 || lvl == -1) {
            cout << "error grade or year." << endl;
        } else
            cout << name << ":" << job << ",Salary:" << 1000 + 500 * lvl + 50 * time << endl;
    }
};

class Teamleader : public Employee {
public:
    Teamleader(string n, string j, int l, int t) :Employee(n, j, l, t) {}
    void salary() {
        if (job == "-1") {
            cout << "error position." << endl;
        } else if (time == -1 || lvl == -1) {
            cout << "error grade or year." << endl;
        } else
            cout << name << ":" << job << ",Salary:" << 3000 + 800 * lvl + 100 * time << endl;
    }
};

class Manager : public Employee {
public:
    Manager(string n, string j, int l, int t) :Employee(n, j, l, t) {}
    void salary() {
        if (job == "-1") {
            cout << "error position." << endl;
        } else if (time == -1 || lvl == -1) {
            cout << "error grade or year." << endl;
        } else
            cout << name << ":" << job << ",Salary:" << 5000 + 1000 * (lvl + time) << endl;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    Employee* people;
    while (t--) {
        string name, job;
        int lvl, year;
        cin >> name >> job >> lvl >> year;
        if (job == "Teamleader") {
            people = new Teamleader(name, job, lvl, year);
            people->salary();
            delete people;
        } else if (job == "Manager") {
            people = new Manager(name, job, lvl, year);
            people->salary();
            delete people;
        } else {
            people = new Employee(name, job, lvl, year);
            people->salary();
            delete people;
        }
    }
    return 0;
}