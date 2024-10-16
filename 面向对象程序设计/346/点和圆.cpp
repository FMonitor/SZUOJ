#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class Point {
private:
    int x, y;
public:
    int getX();
    int getY();
    void setPoint(int x, int y);
};
int Point::getX() {
    return x;
}
int Point::getY() {
    return y;
}
void Point::setPoint(int x, int y) {
    this->x = x;
    this->y = y;
}
class Circle {
private:
    int x, y;
    int r;
public:
    void setCenter(int x, int y);

    void setRadius(int r);

    double getArea();

    double getLength();

    bool check(int x,int y);
};
void Circle::setCenter(int x, int y) {
    this->x = x;
    this->y = y;
}
void Circle::setRadius(int r) {
    this->r = r;
}
double Circle::getArea() {
    return 3.14 * r * r;
}
double Circle::getLength() {
    return 2 * 3.14 * r;
}
bool Circle::check(int x,int y) {
    if (pow(this->x - x,2) + pow(this->y - y,2) > r * r) {
        return 0;
    }
    return 1;
}
int main() {
    int x1, y1, r, x2, y2;
    cin >> x1 >> y1 >> r >> x2 >> y2;
    Point p;
    p.setPoint(x2, y2);
    Circle s;
    s.setCenter(x1, y1);
    s.setRadius(r);
    cout << s.getArea() << " " << s.getLength() << endl;
    if (s.check(p.getX(), p.getY())) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}