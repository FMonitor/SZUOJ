#include<bits/stdc++.h>
using namespace std;

class CCow {
public:
    int age = 0;
    bool alive = 1;
    static int num;
public:
    CCow() {
        num++;
    }
    static void clr() {
        num = 0;
    }
    bool grow() {
        age++;
        if (alive) {
            if (age > 10) {
                alive = 0;
                num--;
                return 0;
            }
            if (age > 3) {
                return 1;
            }
        }
        return 0;
    }

    static int getnum() {
        return num;
    }
};
int CCow::num = 0;
CCow* cow;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--) {
        cow = new CCow[30000];
        CCow::clr();
        int n, index = 0;
        cin >> n;
        cow[index] = CCow();
        // cout << CCow::getnum() << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= index; j++) {
                if (cow[j].grow()) {
                    cow[++index] = CCow();
                    
                }
                // cout << 6 << " " << cow[6].age << " " << cow[6].alive << endl;
            }
        }
        cout << CCow::getnum() << endl;
        delete[]cow;
    }
}


