#include<bits/stdc++.h>
// #include<windows.h>
using namespace std;

double sqrt(double target) {
    double l = 0, r = target;
    int times = 0;
    double mid =0;
    while (fabs(mid * mid - target) > 1e-5) {
        times++;
        mid = (l + r) / 2;
        if (mid * mid < target) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << times << " ";
    return mid;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        double target;
        cin >> target;
        double res = sqrt(target);
        cout << fixed << setprecision(3) << res << endl;
    }
    return 0;
}