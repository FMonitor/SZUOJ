#include<iostream>
#include<string>
using namespace std;

class Lesson {
private:
	string id;
	double score;
	double credit;
public:
	Lesson() {}
	Lesson(string i, double c, double s) {
		id = i;	score = s;	credit = c;
	}
	double getScore() {
		return score;
	}
	double getCredit() {
		return credit;
	}
};

class Student {
private:
	string id;
	string name;
	int type;
	int lesson_num;
	double total_credit;
	Lesson* les;
public:
	Student(string i, string n, int t);
	Student(const Student& stu);
	~Student() {
		delete[] les;
	}
	void record();
	void count();
	void display(char op);
};
//以下填空完成类Student的5个成员函数定义（析构函数已经定义，无需再写）
//注意，类成员函数在类外实现，函数首部要带....
/********** Write your code here! **********/
Student::Student(string i, string n, int t) {
	id = i;
	name = n;
	type = t;
}
Student::Student(const Student& stu) {
	id = "2023";
	id += stu.id;
	name = stu.name;
    type = 1;
    lesson_num = 0;
    int num = 0;
    les = new Lesson[stu.lesson_num];
	for (int i = 0; i < stu.lesson_num; i++) {
		if (stu.les[i].getScore() < 60) {
			continue;
		}
		les[num] = stu.les[i];
		num++;
    }
    lesson_num = num;
}
void Student::record() {
	int n;
	cin >> n;
	les = new Lesson[n];
	lesson_num = n;
	for (int i = 0; i < n; i++) {
		string id;
		double c, s;
		cin >> id >> c >> s;
		les[i] = Lesson(id, c, s);
	}
}
void Student::count() {
	double total = 0;
	for (int i = 0; i < lesson_num; i++) {
		if (les[i].getScore() >= 60) {
			total += les[i].getCredit();
		}
	}
	total_credit = total;
}
void Student::display(char op) {
	if (op == 'D') {
		cout << id << " " << name << " ";
		if (type == 0) {
			cout << "undergraduate" << endl;
		} else {
			cout << "postgraduate" << endl;
		}
	} else if (op == 'C') {
		cout << id << " " << name << " ";
		if (type == 0) {
			cout << "undergraduate " << lesson_num << " " << total_credit << endl;
		} else {
			cout << "postgraduate " << lesson_num << " " << total_credit << endl;
		}
	}
}

/*******************************************/
//主函数
int main() {
	int t;
	// freopen("out.txt", "w", stdout);
	string id, name;
	char op1, op2;
	cin >> t;
	while (t--) {
		cin >> id >> name;
		Student under_stu = Student(id, name, 0);
		under_stu.record();
		under_stu.count();
		Student post_stu = Student(under_stu);
		post_stu.count();

		cin >> op1 >> op2;
		under_stu.display(op1);
		post_stu.display(op2);
	}
	return 0;
}
