#include<bits/stdc++.h>
using namespace std;
int main(){
    const double arr[4]={6.2619,6.6744,0.0516,0.8065};
    const double *p=arr;
    int t;
    cin >> t;
    while(t--){
        char c;
        double mon;
        cin >> c >> mon;
        if(c=='D'){
            cout << fixed << setprecision(4) << mon*(*p) << "\n";
        }else if(c=='E'){
            cout << fixed << setprecision(4) << mon*(*(p+1))<<"\n";   
        }else if(c=='Y'){
            cout << fixed << setprecision(4) << mon*(*(p+2))<<"\n";
        }else{
            cout << fixed << setprecision(4) << mon*(*(p+3))<<"\n";
        }
    }
    return 0;
}