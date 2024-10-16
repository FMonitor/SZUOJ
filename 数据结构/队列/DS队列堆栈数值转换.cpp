#include<bits/stdc++.h>
using namespace std;
char number[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
int main() {
    int t;
    cin >> t;
    while (t--) {
        double n;
        int k;
        cin >> n >> k;
        int i = n;
        double j = n - i;
        stack<int> first;
        queue<int> second;
        while (i != 0) {
            first.push(i % k);
            i /= k;
        }
        int cnt = 0;
        while (j != 0 && cnt<3) {
            second.push(int(j * k));
            j *= k;
            if (int(j) > 0) j -= int(j);
            cnt++;
        }
        cnt = 0;
        while (!first.empty()) {
            int tmp = first.top();
            cout << number[tmp];
            first.pop();
        }
        cout << '.';
        while (!second.empty()) {
            int tmp = second.front();
            cout << number[tmp];
            second.pop();
            cnt++;
            if (cnt == 3)break;
        }
        while (!second.empty()) {
            second.pop();
        }
        while (cnt < 3) {
            cout << "0";
            cnt++;
        }
        cout << endl;
    }
    return 0;
}