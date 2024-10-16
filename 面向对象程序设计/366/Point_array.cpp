#include<bits/stdc++.h>
using namespace std;
class Point {
private:
    double x, y;
public:
    Point();
    Point(double x_value, double y_value);
    ~Point() {
        cout << "Distructor." << endl;
    }
    double getX();
    double getY();
    void setXY(double x1, double y1) {
        x = x1;
        y = y1;
    }
    void setX(double x_value);
    void setY(double y_value);
    double getDisTo(Point& p);
};
Point::Point() {
    cout << "Constructor." << endl;
    x = 0;
    y = 0;
}
Point::Point(double x_value, double y_value) {
    cout << "Constructor." << endl;
    x = x_value;
    y = y_value;
}
double Point::getX() {
    return x;
}
double Point::getY() {
    return y;
}
void Point::setX(double x_value) {
    x = x_value;
}
void Point::setY(double y_value) {
    y = y_value;
}
double Point::getDisTo(Point& p) {
    return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Point p[n];
        double max_dis = 0;
        int ind1=0, ind2=0;
        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            p[i].setXY(x, y);
        }
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                double dis = p[i].getDisTo(p[j]);
                if(dis > max_dis) {
                    max_dis = dis;
                    ind1 = i;
                    ind2 = j;
                }
            }
        }
        cout << "The longeset distance is " << fixed << setprecision(2) << max_dis << ",between p[" << ind1 << "] and p[" << ind2 << "]." << endl;
        
    }
    return 0;
}
