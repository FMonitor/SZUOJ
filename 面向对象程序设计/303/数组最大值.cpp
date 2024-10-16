#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
void search(int* num, int n, int* nmax, int* nmaxindex) {
    int maxn = -INF;
    for (int i = 0; i < n; i++) {
        if (num[i] > maxn) {
            maxn = num[i];
            *nmax = num[i];
            *nmaxindex=&num[i]-num;
        }
    }
    
}
void input(int* num, int n) {
    for(int i=0; i<n; i++) {
        cin >> num[i];
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int* num = new int[n];
        input(num, n);
        int maxn = 0;
        int maxindex = 0;
        int* nmax = &maxn;
        int* nmaxindex=&maxindex;
        search(num, n, nmax, nmaxindex);
        cout << *nmax << " " << *nmaxindex << endl;
        // cout << t << "?";
    }
    return 0;
}