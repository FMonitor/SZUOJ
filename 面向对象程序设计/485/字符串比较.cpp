#include<bits/stdc++.h>
using namespace std;
class str {
    char* p;
public:
    str();
    str(char* s);
    friend bool operator>(str& s1, str& s2);
    friend bool operator<(str& s1, str& s2);
    friend bool operator==(str& s1, str& s2);
    void show() {
        cout << p << endl;
    }
};

str::str() {
    p = new char[1];
    p[0] = '\0';
}

str::str(char* s) {
    p = new char[strlen(s) + 1];
    strcpy(p, s);
}

bool operator>(str& s1, str& s2) {
    for(int i = 0; s1.p[i] != '\0' && s2.p[i] != '\0'; i++) {
        if(s1.p[i] > s2.p[i]) {
            return true;
        } else if(s1.p[i] < s2.p[i]) {
            return false;
        }
    }
    return false;
}

bool operator<(str& s1, str& s2) {
    return !(s1 > s2);
}

bool operator==(str& s1, str & s2) {
    return !(s1 > s2) && !(s1 < s2);
}

int main() {
    char s1[100], s2[100], s3[100];
    cin.getline(s1, 100);
    cin.getline(s2, 100);
    cin.getline(s3, 100);
    str a(s1), b(s2), c(s3);
    if (a > b) {
        a.show();
    } else {
        b.show();
    }
    if (a < c) {
        a.show();
    } else {
        c.show();
    }
    if (b == c) {
        b.show();
    } else {
        c.show();
    }
    return 0;
}