//补充头文件、点类和矩形类
/********** Write your code here! **********/
#include<bits/stdc++.h>
using namespace std;
class CRectangle;
class CPoint {
protected:
    int x, y;
public:
    CPoint(int x, int y) {
        this->x = x;
        this->y = y;
    }
    bool operator==(CPoint& p) {
        if (this->x == p.x && this->y == p.y)
            return true;
        return false;
    }
    friend class CRectangle;
    friend ostream& operator<<(ostream& out, CRectangle& R);
};
class CRectangle {
private:
    CPoint leftPoint, rightPoint;

public:
    CRectangle(int xx1, int yy1, int xx2, int yy2) :leftPoint(xx1, yy1), rightPoint(xx2, yy2) {}
    bool operator>(CPoint& p) {
        if (leftPoint.x <= p.x && leftPoint.y >= p.y && rightPoint.x >= p.x && rightPoint.y <= p.y) {
            return true;
        }
        return false;
    }
    bool operator==(CRectangle& R) {
        if (this->leftPoint == R.leftPoint &&
            this->rightPoint == R.rightPoint)
            return true;
        return false; 
    }
    bool operator>(CRectangle& R) {
        CPoint p1(R.leftPoint.x, R.rightPoint.y);
        CPoint p2(R.rightPoint.x, R.leftPoint.y);
        CPoint p3(this->rightPoint.x, this->leftPoint.y);
        CPoint p4(this->leftPoint.x, this->rightPoint.y);
        if (*this > R.leftPoint || *this > R.rightPoint ||
            *this > p1 || *this > p2 || R>p3 || R>p4 ||
            R>leftPoint || R>rightPoint)
            return true;
        return false;
    }
    bool operator*(CRectangle& R) {
        if (*this>R.leftPoint || *this>R.rightPoint || R>this->leftPoint || R>this->rightPoint) {
            return true;
        }
        return false;
    }
    operator int(){
        return abs((leftPoint.x - rightPoint.x) * (rightPoint.y - leftPoint.y));
    }
    friend ostream& operator<<(ostream& out, CRectangle& R) {
        out << R.leftPoint.x << " " << R.leftPoint.y << " " << R.rightPoint.x << " " << R.rightPoint.y;
        return out;
    }
};

/*******************************************/
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif 
    int t, x1, x2, y1, y2;
    cin >> t;

    while (t--) {
        cin >> x1 >> y1 >> x2 >> y2;  //矩形1的左上角、右下角
        CRectangle rect1(x1, y1, x2, y2);
        cin >> x1 >> y1 >> x2 >> y2;  //矩形2的左上角、右下角
        CRectangle rect2(x1, y1, x2, y2);

        cout << "矩形1:" << rect1 << " " << (int)rect1 << endl;
        cout << "矩形2:" << rect2 << " " << (int)rect2 << endl;

        if (rect1 == rect2)       //判两个矩形相等
            cout << "矩形1和矩形2相等" << endl;
        else if (rect2 > rect1)  //判矩形2包含矩形1
            cout << "矩形2包含矩形1" << endl;
        else if (rect1 > rect2)  //判矩形1包含矩形2
            cout << "矩形1包含矩形2" << endl;
        else if (rect1 * rect2)  //判矩形1和矩形2相交
            cout << "矩形1和矩形2相交" << endl;
        else
            cout << "矩形1和矩形2不相交" << endl;
        cout << endl;
    }
    return 0;
}
