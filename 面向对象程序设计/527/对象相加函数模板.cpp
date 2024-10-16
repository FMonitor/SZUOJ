#include<bits/stdc++.h>
using namespace std;
class CClock {
private:
    int h, m, s;
public:
    CClock(int hour, int min, int sec) :h(hour), m(min), s(sec) {}
    int getH() {
        return h;
    }
    int getM() {
        return m;
    }
    int getS() {
        return s;
    }
    void setH(int n) {
        h = n;
    }
    void setM(int n) {
        m = n;
    }
    void setS(int n) {
        s = n;
    }
};
class CRmb {
private:
    int h, m, s;
public:
    CRmb(int hour, int min, int sec) :h(hour), m(min), s(sec) {}
    int getH() {
        return h;
    }
    int getM() {
        return m;
    }
    int getS() {
        return s;
    }
    void setH(int n) {
        h = n;
    }
    void setM(int n) {
        m = n;
    }
    void setS(int n) {
        s = n;
    }
};
template <class T>
T add(T t1, T t2, int n) {
    int h = t1.getH() + t2.getH();
    int m = t1.getM() + t2.getM();
    int s = t1.getS() + t2.getS();
    if (s >= n) {
        s -= n;
        m++;
    }
    if (m >= n) {
        m -= n;
        h++;
    }
    return T(h, m, s);
}

int main() {
    int h1, m1, s1;
    int h2, m2, s2;
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    CClock c1(h1, m1, s1);
    CClock c2(h2, m2, s2);
    CClock ans = add(c1, c2, 60);
    cout << ans.getH() << " " << ans.getM() << " " << ans.getS() << endl;
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    CRmb r1(h1, m1, s1);
    CRmb r2(h2, m2, s2);
    CRmb ans2 = add(r1, r2, 10);
    cout << ans2.getH() << " " << ans2.getM() << " " << ans2.getS() << endl;
    return 0;
}

