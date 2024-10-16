#include<bits/stdc++.h>
using namespace std;
class Myclock {
private:
    int h, m, s;
public:
    Myclock(int h, int m, int s) : h(h), m(m), s(s) {}
    Myclock() : h(0), m(0), s(0) {}
    Myclock &operator++() {
        this->s++;
        if (this->s == 60) {
            this->s = 0;
            this->m++;
        }
        if (this->m == 60) {
            this->m = 0;
            this->h++;
        }
        if (this->h == 12) {
            this->h = 0;
        }
        return *this;
    }
    Myclock operator--(int) {
        Myclock temp = *this;
        this->s--;
        if (this->s == -1) {
            this->s = 59;
            this->m--;
        }
        if (this->m == -1) {
            this->m = 59;
            this->h--;
        }
        if (this->h == -1) {
            this->h = 11;
        }
        return temp;
    }
    void show() {
        cout << h << ":" << m << ":" << s << endl;
    
    }
};

int main() {
    int h, m, s;
    cin >> h >> m >> s;
    Myclock a(h, m, s);
    int t;
    cin >> t;
    while (t--) {
        int time;
        cin >> time;
        if (time > 0) {
            for (int i = 0; i < time; i++) {
                ++a;    
            }
            a.show();
        } else {
            for(int i = 0; i < -time; i++) {
                a--;
            }
            a.show();
        }
    }
    return 0;
}