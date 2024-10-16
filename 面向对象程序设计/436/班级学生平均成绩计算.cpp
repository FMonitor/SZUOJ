#include<bits/stdc++.h>
using namespace std;
class Person {
protected:
    string name;
    int age;
public:
    Person(string n, double a) :name(n), age(a) {}
    void display() {
        cout << name << " " << age << endl;
    }
};

class Student :public Person {
protected:
    double grade, exam, total;
public:
    Student():Person("",0) {
        grade = 0;
        exam = 0;
        total = 0;
    }
    Student(string n, double a, double g, double e) : Person(n, a), grade(g), exam(e) {
        total = 0.4 * g + 0.6 * e;
    }
    void display() {
        cout << name << " " << age << " " << fixed << setprecision(2) << total << endl;
    }
    double get_total() {
        return total;
    }
};

class Teacher : public Person {
protected:
    double average;
    int student_num;
    Student* students;
public:
    Teacher(string n, double a, int num) : Person(n, a), student_num(num) {
        students = new Student[num];
        average = 0;
        for (int i = 0; i < num; i++) {
            string name;
            double age, grade, exam;
            cin >> name >> age >> grade >> exam;
            students[i] = Student(name, age, grade, exam);
            average += students[i].get_total();
        }
        average /= num;
    }
    void display() {
        if (student_num == 0) average = 0;
        cout << name << " " << age << " " << student_num << " " << fixed << setprecision(2) << average << endl;
        for(int i = 0; i < student_num; i++) {
            students[i].display();
        }
    }
    ~Teacher() {
        delete[] students;
    }
};

int main() {
    string name;
    double age, num;
    cin >> name >> age >> num;
    Teacher t(name, age, num);
    t.display();
    return 0;
}