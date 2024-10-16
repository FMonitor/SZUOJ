#include<bits/stdc++.h>
using namespace std;
class Person {
private:
    string name;
    double height;
    double weight;
    double width;
public:
    Person(string& name, double& height, double& weight, double& width);
    Person() = default;
    void show();
    void set_name(string& name);
    void set_height(double& height);
    void set_weight(double& weight);
    void set_width(double& width);
    string get_name();
    double get_height();
    double get_weight();
    double get_width();
    int get_bmi();
    double get_bfr();
};


Person::Person(string& name, double& height, double& weight, double& width) {
    this->name = name;
    this->height = height;
    this->weight = weight;
    this->width = width;
}
void Person::show() {
    cout << name << " " << height << " " << weight << " " << width << endl;
}
void Person::set_name(string& name) {
    this->name = name;
}
void Person::set_height(double& height) {
    this->height = height;
}
void Person::set_weight(double& weight) {
    this->weight = weight;
}
void Person::set_width(double& width) {
    this->width = width;
}
string Person::get_name() {
    return name;
}
double Person::get_height() {
    return height;
}
double Person::get_weight() {
    return weight;
}
double Person::get_width() {
    return width;
}
int Person::get_bmi() {
    return (weight / (height * height))+0.5;
}
double Person::get_bfr() {
    double a = width * 0.74;
    double b = weight * 0.082+34.89;
    return (a - b) / weight;
}
int main() {
    int n;
    cin >> n;
    Person p[n];
    for (int i = 0; i < n; i++) {
        string name;
        double height, weight, width;
        cin >> name >> height >> weight >> width;
        p[i] = Person(name, height, weight, width);
    }
    for(int i=0;i<n;i++)
    {
        cout << p[i].get_name()<<"'s BMI: "<<p[i].get_bmi()<<"--BFR: "<<fixed<<setprecision(2)<<p[i].get_bfr()<<endl;
    }
    return 0;
}