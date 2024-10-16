#include<bits/stdc++.h>
using namespace std;
int main() {
    queue<int> A;
    queue<int> B;
    int n;
    cin >> n;
    while (n--) {
        int tmp;
        cin >> tmp;
        if (tmp % 2 == 0) {
            B.push(tmp);
        } else {
            A.push(tmp);
        }
    }
    while (!A.empty() || !B.empty()) {
        if (!A.empty()) {
            cout << A.front() << " ";
            A.pop();
        }
        if (!A.empty()) {
            cout << A.front() << " ";
            A.pop();
        }
        if (!B.empty()) {
            cout << B.front() << " ";
            B.pop();
        }
    }
}