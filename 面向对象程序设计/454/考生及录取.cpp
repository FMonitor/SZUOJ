#include<bits/stdc++.h>
using namespace std;

class CExaminee {
private:
    int num;
    double Pscore, Escore, Mscore, Cscore;
    static double total, hun, fif;
public:
    CExaminee(int no, double p, double e, double m, double c) {
        num = no;
        Pscore = p;
        Escore = e;
        Mscore = m;
        Cscore = c;
    }
    static void setscore(int t, int h, int f) {
        total = t;
        hun = h;
        fif = f;
    }
    void isPassed() {
        if (Pscore + Escore + Mscore + Cscore >= total && Pscore >= hun && Escore >= hun && Mscore >= fif && Cscore >= fif) {
            cout << num << "pass" << endl;
        } else {
            cout << num << "fail" << endl;
        }
    }
};
double CExaminee::total = 0;
double CExaminee::hun = 0;
double CExaminee::fif = 0;
int main() {
    int total, hun, fif;
    cin >> total >> hun >> fif;
    CExaminee::setscore(total, hun, fif);
    int t;
    cin >> t;
    while (t--) {
        int n;
        double p, e, m, c;
        cin >> n >> p >> e >> m >> c;
        CExaminee ee(n, p, e, m, c);
        ee.isPassed();
    }
    return 0;
}