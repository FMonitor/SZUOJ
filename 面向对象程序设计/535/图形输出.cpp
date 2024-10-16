#include<bits/stdc++.h>
using namespace std;
class Shape {
protected:
    string name;
    double x;
    double y;
public:
    Shape() {}
    virtual string get_name() {
        return name;
    }
    virtual double get_x() {
        return x;
    }
    virtual double get_y() {
        return y;
    }
    virtual double get_s() {
        return 0.0;
    }
    virtual double get_v() {
        return 0.0;
    }
    virtual void shapeName() = 0;
};
class Point : public Shape {
public:
    Point() {}
    Point(double xn, double yn) {
        x = xn;
        y = yn;
    }
    void shapeName() {
        name = "Point";
    }
    double get_s() {
        return 0.0;
    }
    double get_v() {
        return 0.0;
    }
};
class Circle : public Point {
protected:
    double r;
public:
    Circle() {}
    Circle(double xn, double yn, double rn) {
        x = xn;
        y = yn;
        r = rn;
    }
    void shapeName() {
        name = "Circle";
    }
    double get_s() {
        return r * r * 3.14159;
    }
};
class Cylinder : public Circle {
private:
    double h;
public:
    Cylinder(double xn, double yn, double rn, double hn) {
        x = xn;
        y = yn;
        r = rn;
        h = hn;
    }
    void shapeName() {
        name = "Cylinder";
    }
    double get_s() {
        return r * r * 3.14159 * 2 + 2 * r * 3.14159 * h;
    }
    double get_v() {
        return r * r * h * 3.14159;
    }
};
void Print(Shape* s) {
    cout << s->get_name() << "--(" << s->get_x() << ","
        << s->get_y() << ")--" << (int)s->get_s() << "--"
        << (int)s->get_v() << endl;
    return;
}
int main() {
    double x, y, r, h;
    cin >> x >> y;
    Point p(x, y);
    p.shapeName();
    Print(&p);
    cin >> x >> y >> r;
    Circle cir(x, y, r);
    cir.shapeName();
    Print(&cir);
    cin >> x >> y >> r >> h;
    Cylinder cyl(x, y, r, h);
    cyl.shapeName();
    Print(&cyl);
    return 0;
}