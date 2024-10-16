#include<iostream>
using namespace std;

int isNumber(char* a) {
    int index = 0;
    int ans = 0;
    while (*(a + index) != '\0') {
        if (*(a + index) < '0' || *(a + index) > '9') {
            return -1;
        }
        ans *= 10;
        ans += *(a + index) - '0';
        index++;
    }
    return ans;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        char* p = new char[str.size() + 1];
        for (int i = 0; i < str.size(); i++) {
            *(p + i) = str[i];
        }
        *(p + str.size()) = '\0';
        cout << isNumber(p) << endl;
    }
    return 0;
}