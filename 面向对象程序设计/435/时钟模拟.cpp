#include<bits/stdc++.h>
using namespace std;
class counter {
protected:
    int value;

public:
    counter(int v) : value(v) {};
    void increment() {
        value++;
    }
    int getv(){
        return value;
    }
};

class calcucounter : public counter {
protected:
    int max_value, min_value;
public:
    calcucounter(int v, int maxv, int minv) :counter(v), max_value(maxv), min_value(minv) {};
    bool increment() {
        value++;
        cout << value << endl;
        if (value == max_value) {
            value = min_value;
            return 1;
        }
        return 0;
    }
};

class cclock {
private:
    calcucounter h, m, s;
    int add;
public:
    cclock(int a, int b, int c, int add): h(a, 24, 0),m(b, 60, 0),s(c, 60, 0){
        for (int i = 0; i < add; i++) {
            if (s.increment()) {
                if (m.increment()) {
                    h.increment();
                }
            }
        }
        cout << h.getv() << ":" << m.getv() << ":" << s.getv()<<endl;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, add;
        cin >> a >> b >> c >> add;
        cclock cl(a, b, c, add);
    }
    return 0;
}
