#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    double rate[4]={6.2619,6.6744,0.0516,0.8065};
    while(t--){
        char c;
        int p;
        double mon;
        cin >> c >> mon;
        if(c=='D') p=0;
        if(c=='E') p=1;
        if(c=='Y') p=2;
        if(c=='H') p=3;
        cout << fixed << setprecision(4) << mon*(*(rate+p)) << "\n";
    }
    return 0;
}