#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        vector<int> a;
        int n,sum=0;
        cin >> n;
        for(int i=1; i<n; i++){
            if(n%i==0){
                a.push_back(i);
                sum+=i;
            }
        }
        if(sum==n) cout << "yes";
        else cout << "no";
        for(int i=0; i<a.size(); i++){
            cout <<  ","<<a[i];
        }
        cout << endl;
    }
    return 0;
}