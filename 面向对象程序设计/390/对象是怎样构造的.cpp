#include<bits/stdc++.h>
using namespace std;
class A {
private:
    int num;
public:
    A() {
        num = 0;
        cout << "Constructed by default, value = " << 0 << endl;
    }
    A(int& num) : num(num) {
        cout << "Constructed using one argument constructor, value = " << num<< endl;
    }
    A(const A& a) {
        num = a.num;
        cout << "Constructed using copy constructor, value = " << num << endl;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        switch (n) {
            case 0: {
                A a1;
                break;
            }
            case 1: {
                int num;
                cin >> num;
                A a2(num);
                break;
            }
            case 2: {
                int num;
                cin >> num;
                A a3(num);
                A a4(a3);
                break;
            }
        }
    }
    return 0;
}