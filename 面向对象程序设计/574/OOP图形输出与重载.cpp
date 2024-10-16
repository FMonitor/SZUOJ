#include<bits/stdc++.h>
using namespace std;
class Figure {
private:
    int size;
public:
    Figure() {}
    Figure(int n) :size(n) {}
    friend ostream& operator<<(ostream& os, const Figure& fig) {
        for (int i = 0; i < fig.size; i++) {
            for (int j = 0; j < fig.size; j++) {
                os << '*';
            }
            os << endl;
        }
        os << endl;
        return os;
    }
    Figure& operator++() {
        size++;
        return *this;
    }
    Figure operator++(int) {
        Figure tmp = *this;
        size++;
        // cout << tmp.size << " " << this->size << endl;
        return tmp;
    }
    Figure& operator--() {
        size--;
        return *this;
    }
    Figure operator--(int) {
        Figure tmp = *this;
        size--;
        // cout << tmp.size <<" "<<this->size<< endl;
        return tmp;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int s, opt;
        cin >> s >> opt;
        Figure fig(s);
        for (int i = 0; i < opt; i++) {
            string op;
            cin >> op;
            if (op == "ADD") {
                cout << ++fig;

            } else if (op == "add") {
                cout << fig++;

            } else if (op == "MINUS") {
                cout << --fig;

            } else if (op == "minus") {
                cout << fig--;
            }
        }
        cout << "----------\n";
    }
    return 0;
}