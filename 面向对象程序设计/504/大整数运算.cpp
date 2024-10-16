//补充CBigInteger类和头文件
#include<bits/stdc++.h>
using namespace std;

class CBigInteger {
private:
    static const int MAXN = 1000;
    int num[MAXN];
    int len;
    bool sign;
public:
    CBigInteger() {
        memset(num, 0, sizeof(num));
        len = 1;
    }
    friend istream& operator>>(istream& in, CBigInteger& bigNum) {
        string str;
        in >> str;
        if (str[0] == '-') {
            bigNum.sign = false;
            str = str.substr(1);
        } else {
            bigNum.sign = true;
        }
        while (str[0] == '0' && str.size() > 1)
            str = str.substr(1);
        bigNum.len = str.size();
        for (int i = 0; i < bigNum.len; i++) {
            bigNum.num[i] = str[bigNum.len - i - 1] - '0';
        }
        return in;
    }
    bool operator>(const CBigInteger& bigNum) const {
        if (len != bigNum.len) {
            return len > bigNum.len;
        }
        for (int i = len - 1; i >= 0; i--) {
            if (num[i] != bigNum.num[i]) {
                return num[i] > bigNum.num[i];
            }
        }
        return false;
    }
    friend ostream& operator<<(ostream& out, const CBigInteger& bigNum) {
        bool flag = false;
        if (!bigNum.sign) {
            out << "(-";
            for (int i = bigNum.len - 1; i >= 0; i--) {
                if (bigNum.num[i] == 0 && !flag)
                    continue;
                flag = true;
                out << bigNum.num[i];
            }
            if (!flag) out << "0";
            out << ')';
        } else {
            for (int i = bigNum.len - 1; i >= 0; i--) {
                if (bigNum.num[i] == 0 && !flag)
                    continue;
                flag = true;
                out << bigNum.num[i];
            }
            if (!flag) out << "0";
        }
        
        return out;
    }
    CBigInteger operator+(CBigInteger bigNum) {

        if (sign != bigNum.sign) {
            if (*this > bigNum) {
                CBigInteger rev = bigNum;
                rev.sign = !bigNum.sign;
                return *this - rev;
            } else {
                CBigInteger rev = *this;
                rev.sign = !sign;
                return bigNum - rev;
            }
        }
        CBigInteger res;
        res.len = max(len, bigNum.len);
        res.sign = sign;
        for (int i = bigNum.len;i < len;i++)
            bigNum.num[i] = 0;
        for (int i = len;i < bigNum.len;i++)
            num[i] = 0;
        for (int i = 0; i < res.len; i++) {
            res.num[i] += num[i] + bigNum.num[i];
            res.num[i + 1] += res.num[i] / 10;
            res.num[i] %= 10;
        }
        if (res.num[res.len] > 0) {
            res.len++;
        }
        return res;
    }
    CBigInteger operator-(CBigInteger& bigNum) {

        if (sign != bigNum.sign) {
            CBigInteger rev = bigNum;
            rev.sign = !bigNum.sign;
            return *this + rev;
        }
        CBigInteger res;
        res.len = len;
        for (int i = bigNum.len;i < len;i++)
            bigNum.num[i] = 0;
        for (int i = len;i < bigNum.len;i++)
            num[i] = 0;
        if (bigNum > *this) {
            res.sign = !sign;
            for (int i = 0; i < res.len; i++) {
                res.num[i] = bigNum.num[i] - num[i];
                if (res.num[i] < 0) {
                    res.num[i] += 10;
                    bigNum.num[i + 1]--;
                }
            }
        } else {
            res.sign = sign;
            for (int i = 0; i < res.len; i++) {
                res.num[i] = num[i] - bigNum.num[i];
                if (res.num[i] < 0) {
                    res.num[i] += 10;
                    num[i + 1]--;
                }
            }
        }
        while (res.len > 1 && res.num[res.len - 1] == 0) {
            res.len--;
        }
        return res;
    }
    CBigInteger operator*(const CBigInteger& bigNum) {
        CBigInteger res;
        res.len = len + bigNum.len;
        res.sign = !(sign ^ bigNum.sign);
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < bigNum.len; j++) {
                res.num[i + j] += num[i] * bigNum.num[j];
                res.num[i + j + 1] += res.num[i + j] / 10;
                res.num[i + j] %= 10;
            }
        }
        while (res.len > 1 && res.num[res.len - 1] == 0) {
            res.len--;
        }
        return res;
    }

};
int main() {
    int t;
    char op;
    CBigInteger bigNum1;
    CBigInteger bigNum2;

    cin >> t;
    while (t--) {
        cin >> bigNum1 >> op >> bigNum2;
        cout << bigNum1 << " " << op << " " << bigNum2 << " = ";
        if (op == '+')
            cout << bigNum1 + bigNum2 << endl;
        else if (op == '-')
            cout << bigNum1 - bigNum2 << endl;
        else if (op == '*')
            cout << bigNum1 * bigNum2 << endl;
    }
    return 0;
}