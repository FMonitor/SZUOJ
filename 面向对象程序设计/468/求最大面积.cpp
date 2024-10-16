#include<bits/stdc++.h>
using namespace std;

class Geometry {
public:
    virtual double getArea() = 0;
};

class Rect :public Geometry {
private:
    double length;
    double width;
public:
    Rect(double l, double w) {
        length = l;
        width = w;
    }
    double getArea() {
        return length * width;
    }
};

class Circle :public Geometry {
private:
    double radius;
public:
    Circle(double r) {
        radius = r;
    }
    double getArea() {
        return radius * radius * 3.14;
    }
};

class TotalArea {
public:
    static void computerMadxArea(Geometry** t, int n) {
        double mx = 0;
        for (int i = 0; i < n; i++) {
            mx =max(mx, t[i]->getArea());
        }
        cout << "最大面积=" << fixed << setprecision(2) << mx ;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    Geometry** t = new Geometry * [n];
    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, w;
            cin >> l >> w;
            t[i] = new Rect(l, w);
        } else {
            int r;
            cin >> r;
            t[i] = new Circle(r);
        }
    }
    TotalArea::computerMadxArea(t, n);
    for (int i = 0; i < n; i++) {
        delete t[i];
    }
    delete[] t;
    return 0;
}