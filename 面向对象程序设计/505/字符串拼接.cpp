#include <cstring>
#include <iostream>
using namespace std;

class CString {
    char* s;
    int n;
public:
    CString(char* const _s = nullptr) : s(nullptr), n(0) {
        if (!_s)
            return;
        n = strlen(_s);
        s = new char[n + 1] {};
        strncpy(s, _s, n); // 记得 #include <cstring>
    }
    ~CString() {
        delete[]s;
    }

    // 1. 要求重载 '+' 运算符, 实现两个CString对象相加的结果
    //   （不能改变原来的两个CString对象）
    // ...可以补充其它成员函数...


/********** Write your code here! **********/
    CString &operator=(const CString& rhs) {
        if (this->s) {
            delete[]s;
        }
        n = rhs.n;
        s = new char[rhs.n + 1];
        strncpy(s, rhs.s, rhs.n);
        return *this;
    }
    CString(CString& rhs) {
        n = rhs.n;
        s = new char[rhs.n+1];
        strcpy(s, rhs.s);
    }
    CString operator+(const CString& rhs) {
        CString res;
        res.n = n + rhs.n;
        res.s = new char[res.n + 1];
        for (int i = 0; i < n; i++) {
            res.s[i] = s[i];
        }
        for (int i = 0; i < rhs.n; i++) {
            res.s[i + n] = rhs.s[i];
        }
        res.s[res.n] = '\0';
        return res;
    }
    friend ostream& operator<<(ostream& out, const CString& str) {
        out << str.s;
        return out;
    }
};
/*******************************************/
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif  
    int n;
    char input[64 + 1]{}; // ! strlen(s) + 1
    cin >> n;
    while (n--) {
        cin >> input;
        CString s1(input);
        cin >> input;
        CString s2(input);

        CString sEmpty;                   // !
        delete new CString(s1 = s1 + s2); // !

        cout << s1 + sEmpty << endl
            << sEmpty + s2 << endl
            << s1 + s2 << endl
            << endl;
    }
    return 0;
}