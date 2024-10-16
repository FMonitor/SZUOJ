#include<bits/stdc++.h>
using namespace std;
class Student {
private:
    string name;
    string number;
    string college;
    string major;
    string sex;
    string address;
    string phone;
public:
    Student(string name, string number, string college, string major,
        string sex, string address, string phone);
    Student() = default;
    void show();
    void set_name(string name);
    void set_number(string number);
    void set_college(string college);
    void set_major(string major);
    void set_sex(string sex);
    void set_address(string address);
    void set_phone(string phone);
    string get_name();
    string get_number();
    string get_college();
    string get_major();
    string get_sex();
    string get_address();
    string get_phone();
};
Student::Student(string name, string number, string college, string major,
    string sex, string address, string phone) {
    this->name = name;
    this->number = number;
    this->college = college;
    this->major = major;
    this->sex = sex;
    this->address = address;
    this->phone = phone;
}

void Student::show() {
    cout << name << " " << number << " " << college << " " << major
        << " " << sex << " " << address << " " << phone << endl;
}
void Student::set_name(string name) {
    this->name = name;
}
void Student::set_number(string number) {
    this->number = number;
}
void Student::set_college(string college) {
    this->college = college;
}
void Student::set_major(string major) {
    this->major = major;
}
void Student::set_sex(string sex) {
    this->sex = sex;
}
void Student::set_address(string address) {
    this->address = address;
}
void Student::set_phone(string phone) {
    this->phone = phone;
}
string Student::get_name() {
    return name;
}
string Student::get_number() {
    return number;
}
string Student::get_college() {
    return college;
}
string Student::get_major() {
    return major;
}
string Student::get_sex() {
    return sex;
}
string Student::get_address() {
    return address;
}
string Student::get_phone() {
    return phone;
}
int main() {
    int n;
    cin >> n;
    Student stu[n];
    for (int i = 0; i < n; i++) {
        string name, number, college, major, sex, address, phone;
        cin >> name >> number >> college >> major >>
            sex >> address >> phone;
        stu[i] = Student(name, number, college, major,sex, address, phone);
    }
    for(int i = 0; i < n; i++) {
        stu[i].show();
    }
    return 0;
}