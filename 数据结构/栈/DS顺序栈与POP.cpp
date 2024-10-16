#include<bits/stdc++.h>
using namespace std;

class SqStack {
    int* top;
    int* base;
public:
    static bool InitStack(SqStack &S) {
        S.base = new int[1000];
        S.top = S.base;
        return true;
    }
    static bool Push(SqStack& S, int e) {
        if ((S.top - S.base) > 1000)
            return false;
        *S.top++ = e;
        S.printTop();
        return true;
    }
    static bool Pop(SqStack& S, int& e) {
        if ((S.top == S.base))
            return false;
        e = *--S.top;
        S.printTop();
        return true;
    }
    int GetTop(SqStack S) {
        int* tmp = S.top;
        return *(tmp--);
    }
    void printTop() {
        if (top != base) {
            cout << *(top-1) << endl;
        } else {
            cout << "empty" << endl;
        }
    }
};

int main() {
    int t;
    cin >> t;
    SqStack S;
    SqStack::InitStack(S);
    while (t--) {
        string op;
        int num=0;
        cin >> op;
        if (op == "push") {
            cin >> num;
            SqStack::Push(S,num);
        } else {
            if (!SqStack::Pop(S,num)) {
                cout << "error" << endl;
            }
        }
    }
    return 0;
}