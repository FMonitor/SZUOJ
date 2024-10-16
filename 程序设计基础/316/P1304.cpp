#include<bits/stdc++.h>
using namespace std;
bool isprime(int a){
    if(a==0 && a==1){
        return 0;
    }
    for(int i=2; i<=sqrt(a); i++){
        if(a%i==0) return 0;
    }
    return 1;
}
int main(){
    int n;
    cin >> n;
    for(int i=4; i<=n; i+=2){
        for(int j=2; j<=n; j++){
            if(isprime(j) && isprime(i-j)){
                cout << i << "=" << j << "+" << i-j << endl;
                break;
            }
        }
    }
    return 0;
}