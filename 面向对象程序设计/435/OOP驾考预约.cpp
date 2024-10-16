#include<bits/stdc++.h>
using namespace std;
class CPerson {
protected:
    string name;
    string phone;
public:
    CPerson(string n, string p) :name(n), phone(p) {};
};

class Student : public CPerson {
protected:
    int Atime[12]={0};
public:
    Student(string n, string p) :CPerson(n, p) {
        for (int i = 0; i < 12;i++) {
            int tmp;
            cin >> tmp;
            if (tmp >= 60) {
                Atime[i]++;
            }
        }
    };
    void Check() {
        int cnt = 0;
        for (int i = 0; i < 12; i++) {
            cnt += Atime[i];
        }
        if (cnt >= 10) {
            cout << name << "达到学时要求可以预约！电话" << phone << endl;
        } else {
            cout << name << "未达到学时要求不能预约！电话" << phone << endl;
        }
    }
};

class VIPS : public Student {
public:
    VIPS(string n, string p) : Student(n, p) {
        for (int i = 0; i < 12; i++) {
            int tmp;
            cin >> tmp;
            if (tmp > 60) {
                if (tmp < 120) {
                    Atime[i]++;
                } else {
                    Atime[i] += 2;
                }
            }
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        char type;
        string n, p;
        cin >> type >> n >> p;
        if (type == 'F') {
            Student s(n, p);
            s.Check();
        } else {
            VIPS s(n, p);
            s.Check();
        }        
    }
    return 0;
}