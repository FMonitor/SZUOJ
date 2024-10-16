#include<bits/stdc++.h>
using namespace std;

class CPoint {
protected:
    int x;
    int y;
    int dir;
public:
    CPoint(int xx = 0, int yy = 0, int dd = 1) {
        x = xx;
        y = yy;
        dir = dd;
    }
    int get_x() {
        return x;
    }
    int get_y() {
        return y;
    }
    int get_d() {
        return dir;
    }
    void set_x(int n) {
        x = n;
    }
    void set_y(int n) {
        y = n;
    }
    void set_d(int n) {
        dir = n;
    }
};

class CHole :public CPoint {
public:
    CHole(int xx = 0, int yy = 0, int dd = 1) {
        x = xx;
        y = yy;
        dir = dd;
    }
};
class CTriangle :public CPoint {
    //1 leftup,2 rightup,3 rightdown,4 leftdown
public:
    CTriangle(int xx = 0, int yy = 0, int dd = 1) {
        x = xx;
        y = yy;
        dir = dd;
    }
    CTriangle& operator++() {
        if (dir + 1 > 4)
            dir = 1;
        else
            dir++;
        return *this;
    }
};
class CBall :public CPoint {
    //1 right,2 up,3 left,4 down
public:
    CBall(int xx = 0, int yy = 0, int dd = 1) {
        x = xx;
        y = yy;
        dir = dd;
    }
    CBall& operator*=(CTriangle tr) {
        if (this->get_x() != tr.get_x() || this->get_y() != tr.get_y()) {
            return *this;
        }
        if (dir == 1) {
            if (tr.get_d() == 1) {
                dir = 2;
            } else if (tr.get_d() == 4) {
                dir = 4;
            } else {
                dir = 3;
            }
        } else if (dir == 2) {
            if (tr.get_d() == 3) {
                dir = 1;
            } else if (tr.get_d() == 4) {
                dir = 3;
            } else {
                dir = 4;
            }
        } else if (dir == 3) {
            if (tr.get_d() == 2) {
                dir = 2;
            } else if (tr.get_d() == 3) {
                dir = 4;
            } else {
                dir = 1;
            }
        } else {
            if (tr.get_d() == 1) {
                dir = 3;
            } else if (tr.get_d() == 2) {
                dir = 1;
            } else {
                dir = 2;
            }
        }
        return *this;
    }
    CBall& operator++() {
        if (dir == 1) {
            x++;
            return *this;
        }
        if (dir == 2) {
            y--;
            return *this;
        }
        if (dir == 3) {
            x--;
            return *this;
        }
        if (dir == 4) {
            y++;
            return *this;
        }
    }
};
class Game {
private:
    int n, m, k;
    CTriangle* trs;
    CBall ball;
    CHole red, blue;
    bool map[100][100];
    bool flag;
public:
    Game() {
        n = 0;
        m = 0;
        k = 0;
        flag = 0;
        memset(map, 0, sizeof(map));
    }
    Game(int nn, int mm, int cnt) {
        n = n;
        m = m;
        k = 0;
        flag = 0;
        trs = new CTriangle[cnt];
        memset(map, 0, sizeof(map));
    }
    void set_Hole(CHole r, CHole b) {
        red = r;
        blue = b;
        ball.set_x(red.get_x());
        ball.set_y(red.get_y());
        ball.set_d(red.get_d());
    }
    void add_tri(CTriangle tr) {
        trs[k] = tr;
        map[tr.get_x()][tr.get_y()] = 1;
        k++;
    }
    friend ostream& operator<<(ostream& os, const Game g) {
        if (g.flag)
            os << "no solution" << endl;
        else {
            for (int i = 0; i < g.k; i++) {
                os << g.trs[i].get_x() << " " << g.trs[i].get_y()
                    << " " << g.trs[i].get_d() << endl;
            }
        }
        return os;
    }
    void start() {
        int x = ball.get_x();
        int y = ball.get_y();
        int d = ball.get_d();
        flag = 1;
        move(x, y, d);
    }
    void move(int x, int y, int d) {
        if (!flag) {
            return;
        }
        if (x == blue.get_x() && y == blue.get_y() && d == blue.get_d()) {
            flag = 0;
            return;
        }
        if (x >= n || x < 0 || y < 0 || y >= m) {
            return;
        }
        if (map[x][y]) {
            for (int i = 0; i < k; i++) {
                if (trs[i].get_x() == x && trs[i].get_y() == y) {
                    for (int j = 0; j < 4; j++) {
                        CBall tmp(x, y, d);
                        tmp *= trs[i];
                        if (abs(tmp.get_d() - d) == 2) {
                            continue;
                        }
                        if (d == 1) {
                            move(x, y + 1, d);
                        } else if (d == 2) {
                            move(x - 1, y, d);
                        } else if (d == 3) {
                            move(x, y - 1, d);
                        } else if (d == 4) {
                            move(x + 1, y, d);
                        }


                    }
                }
            }
        }

    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int x, y, d;
        cin >> x >> y >> d;
        CHole red(x, y, d);
        cin >> x >> y >> d;
        CHole blv(x, y, d);
        int tri;
        cin >> tri;
        Game g(n, m, tri);
        g.set_Hole(red, blv);
        while (tri--) {
            cin >> x >> y >> d;
            CTriangle tr(x, y, d);
            g.add_tri(tr);
        }
        cout << g << endl;
    }
}