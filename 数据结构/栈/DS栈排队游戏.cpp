#include<bits/stdc++.h>
using namespace std;
int main() {
    stack<int> s;
    char tmp;
    cin >> tmp;
    int cnt = 0;
    s.push(cnt);
    cnt++;
    char now;
    while (cin >> now) {
        if (now != tmp) {
            cout << s.top() << " " << cnt<<endl;
            s.pop();
            cnt++;
            continue;
        } else {
            s.push(cnt);   
        }
        cnt++;
    }
    return 0;
}