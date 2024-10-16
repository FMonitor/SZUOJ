#include<bits/stdc++.h>
using namespace std;

class CDate {
private:
    int year;
    int month;
    int day;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
public:
    CDate(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }
    void add() {
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
            days[1] = 29;
        } else {
            days[1] = 28;
        }
        day++;
        if (day > days[month - 1]) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }
    int cmp(CDate now) {
        if (now.year == year) {
            if (now.month == month) {
                if (now.day > day) {
                    return 1;
                } else if (now.day == day) {
                    return 0;
                } else {
                    return -1;
                }
            } else {
                if (now.month > month) {
                    return 1;
                } else {
                    return -1;
                }
            }
        } else {
            if (now.year > year) {
                return 1;
            } else {
                return -1;
            }
        }
        return 0;
    }
};

class Pet {
protected:
    string name;//姓名
    float length;//身长
    float weight;//体重
    CDate current;//开始记录时间
    int cnt;
public:
    Pet(string n, float l, float w, int y, int m, int d) :current(y, m, d), name(n), length(l), weight(w) {
        cnt = 0;
    }
    virtual void display(CDate day) = 0;//输出目标日期时宠物的身长和体重
};

class Cat : public Pet {
public:
    Cat(string n, float l, float w, int y, int m, int d) :Pet(n, l, w, y, m, d) {};
    void display(CDate day) {
        if (day.cmp(current)==1) {
            cout << "error" << endl;
            return;
        }
        while (day.cmp(current)!=0) {
            current.add();
            cnt++;
            length += 0.1;
            weight += 0.2;
        }
        cout << name << " after " << cnt << " day: length="
            << fixed << setprecision(2) << length << ",weight="
            << fixed << setprecision(2) << weight << endl;
    }
};

class Dog : public Pet {
public:
    Dog(string n, float l, float w, int y, int m, int d) :Pet(n, l, w, y, m, d) {};
    void display(CDate day) {
        if (day.cmp(current)==1) {
            cout << "error" << endl;
            return;
        }
        while (day.cmp(current)!=0) {
            current.add();
            cnt++;
            length += 0.2;
            weight += 0.1;
        }
        cout << name << " after " << cnt << " day: length="
            << fixed << setprecision(2) << length << ",weight="
            << fixed << setprecision(2) << weight << endl;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int t;
    cin >> t;
    int y, m, d;
    cin >> y >> m >> d;
    Pet* pt;
    while (t--) {
        int type;
        cin >> type;
        string name;
        float length, weight;
        int year, month, day;
        cin >> name >> length >> weight >> year >> month >> day;
        CDate Day(year, month, day);
        if (type == 1) {
            pt = new Cat(name, length, weight, y, m, d);
            pt->display(Day);
            delete pt;
        } else {
            pt = new Dog(name, length, weight, y, m, d);
            pt->display(Day);
            delete pt;
        }
    }
    return 0;
}