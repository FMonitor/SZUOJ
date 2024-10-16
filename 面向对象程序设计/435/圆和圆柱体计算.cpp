#include<bits/stdc++.h>
using namespace std;
class CPoint {
protected:
    int x, y;
public:
    CPoint() {};
    CPoint(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

class CCircle : public CPoint{
protected:
    double r;
public:
    CCircle(int x, int y, int r) : CPoint(x, y), r(r) {}
    double Area() {
        return 3.14 * r * r;
    }
};

class CCylinder : public CCircle {
private:
    int h;
public:
    CCylinder(int x, int y, int r, int h) : CCircle(x, y, r), h(h) {}
    double Volume() {
        return Area() * h;
    }
};

int main() {
    int x1, y1, r1;
    cin >> x1 >> y1 >> r1;
    int x2, y2, r2, h;
    cin >> x2 >> y2 >> r2 >> h;
    CCircle a(x1, y1, r1);
    CCylinder b(x2, y2, r2, h);
    printf("Circle:(%d,%d),%d\n", x1, y1, r1);
    cout << "Area:"<<a.Area() << endl;
    printf("Cylinder:(%d,%d),%d,%d\n", x2, y2, r2, h);
    cout << "Volume:" << b.Volume() << endl;
}