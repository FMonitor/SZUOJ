#include<bits/stdc++.h>
using namespace std;

class Group {
public:
    virtual int add(int x, int y) = 0;
    virtual int sub(int x, int y) = 0;
};

class GroupA : public Group {
public:
    int add(int x, int y) {
        return x + y;
    }
    int sub(int x, int y) {
        return x - y;
    }
};

class GroupB : public Group {
public:
    int add(int x, int y) {
        return x + y;
    }
    int sub(int x, int y) {
        int ans = 0,cnt=0;
        int tmp = x;
        while (tmp > 0) {
            tmp/= 10;
            cnt++;
        }
        for (int i = 0; i < cnt; i++) {
            int tmp1 = x % 10 - y % 10;
            x /= 10;
            y /= 10;
            tmp1 = tmp1 < 0 ? tmp1 + 10 : tmp1;
            ans += tmp1 * pow(10, i);
        }
        return ans;
    }
};

class GroupC : public Group {
public:
    int add(int x, int y) {
        int ans = 0,cnt=0;
        int tmp = x;
        while (tmp > 0) {
            tmp %= 10;
            cnt++;
        }
        for (int i = 0; i < cnt; i++) {
            int tmp1 = x % 10 + y % 10;
            x /= 10;
            y /= 10;
            tmp1 = tmp1 > 9 ? tmp1 - 10 : tmp1;
            ans += tmp1 * pow(10, i);
        }
        return ans;
    }
    int sub(int x, int y) {
        int ans = 0,cnt=0;
        int tmp = x;
        while (tmp > 0) {
            tmp/= 10;
            cnt++;
        }
        for (int i = 0; i < cnt; i++) {
            int tmp1 = x % 10 - y % 10;
            x /= 10;
            y /= 10;
            tmp1 = tmp1 < 0 ? tmp1 + 10 : tmp1;
            ans += tmp1 * pow(10, i);
        }
        return ans;
    }
};

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    Group* s;
    for (int i = 0; i < n; i++) {
        string cal;
        int flag = 0, a=0, b=0, type;
        cin >> type >> cal;
        for (int i = 0; i < cal.size(); i++) {
            if (cal[i] == '+') {
                flag = 1;
                continue;
            }
            if (cal[i] == '-') {
                flag = -1;
                continue;
            }
            if (flag == 0) {
                a = a * 10 + cal[i] - '0';
            } else {
                b = b * 10 + cal[i] - '0';
            }
        }
        if (type == 1) {
            s = new GroupA;
            if (flag == 1) {
                cout << s->add(a, b) << endl;
            } else {
                cout << s->sub(a, b) << endl;
            }
        } else if (type == 2) {
            s = new GroupB;
            if (flag == 1) {
                cout << s->add(a, b) << endl;
            } else {
                cout << s->sub(a, b) << endl;
            }
        } else if (type == 3) {
            s = new GroupC;
            if (flag == 1) {
                cout << s->add(a, b) << endl;
            } else {
                cout << s->sub(a, b) << endl;
            }
        }
    }
    return 0;
}