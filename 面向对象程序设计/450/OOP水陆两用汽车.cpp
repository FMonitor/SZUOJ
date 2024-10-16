#include<bits/stdc++.h>
using namespace std;
class Vehicle {
protected:
    double weight;
public:
    Vehicle(double w) : weight(w) {
        cout <<"载入Vehicle类构造函数\n";
    }
    void setWeight(double w) {
        weight = w;
        cout<<"重新设置重量\n";
    }
    void display() {
        cout << "重量：" << weight << "吨";
    }
};
class Car : virtual public Vehicle {
protected:
    double aird;
public:
    Car(double w, double a) :Vehicle(w), aird(a) {
        cout << "载入Car类构造函数\n";
    }
    void setAird(double a) {
        cout << "重新设置空气排量\n";
        aird = a;
    }
    void c_display() {
        this->display();
        cout <<"，空气排量："<<aird<<"CC";
    }
};
class Boat : virtual public Vehicle {
protected:
    double tonnage;
public:
    Boat(double w, double a) :Vehicle(w), tonnage(a) {
        cout << "载入Boat类构造函数\n";
    }
    void setTonnage(double a) {
        cout << "重新设置排水量\n";
        tonnage = a;
    }
    void b_display() {
        this->display();
        cout <<"，排水量："<<tonnage<<"吨";
    }
};
class AmphibianCar : public Car ,public Boat{
public:
    AmphibianCar(double w, double a,double t) :Vehicle(w), Boat(w,t),Car(w,a) {
        cout << "载入AmphibianCar类构造函数\n";
    }
    void a_display() {
        this->display();
        cout <<"，空气排量："<<aird<<"CC";
        cout <<"，排水量："<<tonnage<<"吨\n";
    }
};
int main() {
    double w1,a1,t1;
    double w2,a2,t2;
    cin >> w1 >> a1 >> t1 >> w2 >> a2 >> t2;
    AmphibianCar am(w1,a1,t1);
    am.a_display();
    am.setWeight(w2);
    am.setAird(a2);
    am.setTonnage(t2);
    am.a_display();

}