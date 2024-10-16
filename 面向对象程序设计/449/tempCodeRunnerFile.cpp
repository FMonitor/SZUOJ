#include<bits/stdc++.h>
using namespace std;
class CVehicle {
protected:
    int max_speed;
    int speed;
    int weight;
public:
    CVehicle(int m, int s, int w) : max_speed(m), speed(s), weight(w) {}
    void v_display() {
        cout << "Vehicle:\n";
        display();
        cout <<"\n";
    }
    void display() {
        cout << "max_speed:" << max_speed << "\nspeed:" << speed << "\nweight:" << weight << "\n";
    }
};

class CBycicle : virtual public CVehicle {
protected:
    int height;
public:
    CBycicle(int m, int s, int w, int h) :CVehicle(m, s, w), height(h) {}
    void b_display() {
        cout << "Bicycle:\n";
        display();
        cout << "height:" << height << "\n\n";
    }
};

class CMotocar : virtual public CVehicle {
protected:
    int seat_num;
public:
    CMotocar(int m, int s, int w, int n) :CVehicle(m, s, w), seat_num(n) {}
    void c_display() {
        cout << "Motocar\n";
        display();
        cout << "seat_num:" << seat_num << "\n\n";
    }
};

class Motocycle :public CBycicle, public CMotocar {
public:
    Motocycle(int m, int s, int w, int h, int n):CMotocar(m, s, w, n),CBycicle(m, s, w, h),CVehicle(m, s, w) {}
    void mc_display() {
        cout << "Motocycle:\n";
        display();
        cout << "height:" << height << "\n";
        cout << "seat_num:" << seat_num;
    }
};

int main() {
    int m, s, w, h, n;
    cin >> m >> s >> w >> h >> n;
    CVehicle v(m, s, w);
    v.v_display();
    CBycicle b(m, s, w, h);
    b.b_display();
    CMotocar c(m, s, w, n);
    c.c_display();
    Motocycle mc(m, s, w, h, n);
    mc.mc_display();
    return 0;
}