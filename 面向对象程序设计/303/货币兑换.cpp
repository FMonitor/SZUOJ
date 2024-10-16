#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    const double ratio[4] = { 6.2619,6.6744,0.0516,0.8065 };
    while (t--) {
        char type;
        double cnt;
        cin >> type >> cnt;
        const double* p = nullptr;
        if (type == 'D') p = ratio;
        else if(type=='E') p=ratio+1;
        else if(type=='Y') p=ratio+2;
        else p=ratio+3;
        cout << fixed << setprecision(4) << cnt * (*p) << endl;
    }
    return 0;
}