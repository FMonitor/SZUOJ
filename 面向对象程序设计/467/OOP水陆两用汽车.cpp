#include<bits/stdc++.h>
using namespace std;
class Vehicle {
protected:
    double weight;
public:
    Vehicle(double w) : weight(w) {
        cout <<"����Vehicle�๹�캯��\n";
    }
    void setWeight(double w) {
        weight = w;
        cout<<"������������\n";
    }
    virtual void display() {
        cout << "������" << weight << "��";
    }
};
class Car : virtual public Vehicle {
protected:
    double aird;
public:
    Car(double w, double a) :Vehicle(w), aird(a) {
        cout << "����Car�๹�캯��\n";
    }
    void setAird(double a) {
        cout << "�������ÿ�������\n";
        aird = a;
    }
    virtual void display() {
        cout << "������" << weight << "��";
        cout <<"������������"<<aird<<"CC";
    }
};
class Boat : virtual public Vehicle {
protected:
    double tonnage;
public:
    Boat(double w, double a) :Vehicle(w), tonnage(a) {
        cout << "����Boat�๹�캯��\n";
    }
    void setTonnage(double a) {
        cout << "����������ˮ��\n";
        tonnage = a;
    }
    virtual void display() {
        cout << "������" << weight << "��";
        cout <<"����ˮ����"<<tonnage<<"��";
    }
};
class AmphibianCar : public Car ,public Boat{
public:
    AmphibianCar(double w, double a,double t) :Vehicle(w), Boat(w,t),Car(w,a) {
        cout << "����AmphibianCar�๹�캯��\n";
    }
    void display() {
        cout << "������" << weight << "��";
        cout <<"������������"<<aird<<"CC";
        cout <<"����ˮ����"<<tonnage<<"��\n";
    }
};
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    double w1, a1, t1;
    double w2,a2,t2;
    cin >> w1 >> a1 >> t1 >> w2 >> a2 >> t2;
    AmphibianCar am(w1,a1,t1);
    am.display();
    am.setWeight(w2);
    am.setAird(a2);
    am.setTonnage(t2);
    am.display();
    return 0;
}