#include<bits/stdc++.h>
using namespace std;
class Shape {
protected:
    string name;
    double x, y;
public:
    Shape() {}
    Shape(double xx, double yy) :x(xx), y(yy) {}
    virtual void shapeName() {}
    double getx(){
        return x;
    }
    double gety() {
        return y;
    }
    virtual double gets(){
        return 0;
    }
    virtual double getv(){
        return 0;
    }
    string getname() {
        return name;
    }
};

class Point : public Shape {
public:
    Point(double xx, double yy) :Shape(xx, yy) {
        shapeName();
    }
    void shapeName() {
        name = "Point";
    }
    
};

class Circle : public Point {
protected:
    double r;
public:
    Circle(double xx, double yy, double rr) :Point(xx, yy), r(rr) {
        shapeName();
    }
    void shapeName() {
        name = "Circle";
    }
    double gets(){
        return (int)(r * r * 3.14159);
    }
};

class Cylinder : public Circle {
protected:
    double h;
public:
    Cylinder(double xx, double yy, double rr, double hh) :Circle(xx, yy, rr), h(hh) {
        shapeName();
    }
    void shapeName() {
        name = "Cylinder";
    }
    double gets() {
        return (int)(6.28 * r * r + 3.14159*2 * r * h);
    }
    double getv() {
        return (int)(r * r * 3.14159 * h);
    }
};

void Print(Shape* s) {
    cout << s->getname() << "--(" << s->getx() <<
        "," << s->gety() << ")--" << s->gets() <<
        "--"  <<  s->getv() << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("out.txt", "w", stdout);
#endif
    double x, y, r, h;
    cin >> x >> y;
    Shape* s = new Point(x, y);
    Print(s);
    delete s;
    cin >> x >> y >> r;
    s = new Circle(x, y, r);
    Print(s);
    delete s;
    cin >> x >> y >> r >> h;
    s = new Cylinder(x, y, r, h);
    Print(s);
    delete s;
    return 0;
}