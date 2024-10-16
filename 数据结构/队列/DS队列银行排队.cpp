#include<bits/stdc++.h>
using namespace std;
int main() {
    queue<char> Clinet;
    queue<int> Time;
    int n;
    cin >> n;
    double a = 0;
    double b = 0;
    double c = 0;
    int asize = 0;
    int bsize = 0;
    int csize = 0;
    for (int i = 0; i < n; i++) {
        char tmp;
        cin >> tmp;
        Clinet.push(tmp);
    }
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        Time.push(tmp);
    }
    for (int i = 0; i < n; i++) {
        char now = Clinet.front();
        if (now == 'A') {
            asize++;
            a += Time.front();
        } else if (now == 'B') {
            bsize++;
            b += Time.front();
        } else if (now == 'C') {
            
            csize++;
            c += Time.front();
        }
        Clinet.pop();
        Time.pop();
    }
    cout << a / asize << endl << b / bsize << endl << c / csize << endl;
    return 0;
}