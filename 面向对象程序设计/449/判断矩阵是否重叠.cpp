#include<bits/stdc++.h>
using namespace std;
class CPoint {
protected:
    int x, y;
public:
    CPoint(int x, int y) :x(x), y(y) {}
    int getX(){
        return x;
    }
    int getY() {
        return y;
    }
};

class CRect {
protected:
    CPoint p1, p2;
public:
    CRect(CPoint a, CPoint b) :p1(a), p2(b) {};
    friend bool isoverlap(CRect, CRect);
};

bool isoverlap(CRect s1, CRect s2) {
    if (s1.p2.getX() < s2.p1.getX() || s2.p2.getX() < s1.p1.getX() || s1.p1.getY() > s2.p2.getY() ) {
        return false;
    } else {
        return true;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        
        int x11, y11, x12, y12;
        int x21, y21, x22, y22;
        cin >> x11 >> y11 >> x12 >> y12
            >> x21 >> y21 >> x22 >> y22;
        if (x11 > x12) swap(x11, x12);
        if (y11 > y22) swap(y11, y12);
        if (x21 > x22) swap(x21, x22);
        if (y21 > y22) swap(y21, y22);
        CPoint s11(x11, y11), s12(x12, y12);
        CPoint s21(x21, y21), s22(x22, y22);
        CRect r1(s11, s12),r2(s21,s22);
        if (isoverlap(r1,r2)) {
            cout << "overlapped" << endl;
        } else {
            cout << "not overlapped" << endl;
        }
    }
    return 0;
}