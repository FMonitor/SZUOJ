#include<bits/stdc++.h>
using namespace std;
class CUser {
protected:
    string name;
    int coin;
    static string king;
    static int kingc;
    static int total;
public:
    CUser(string n, int c) :name(n), coin(c) {
        total += c / 2500;
        if (coin > kingc) {
            kingc = coin;
            king = name;
        }
    }
    void static Print() {
        cout << "The most attentive user :" << king << ",and he/she has " << kingc
            << " gold coins.\nThere are " << total << " more trees in the world!\n";
    }
    void static reset() {
        kingc = 0;
        king = "null";
        total = 0;
    }
};
int CUser::total = 0;
int CUser::kingc = 0;
string CUser::king = "null";

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string n;
            int c;
            cin >> n >> c;
            CUser co(n, c);
        }
        CUser::Print();
        CUser::reset();
    }
    return 0;
}
