#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int n,k;
   cin >> n >> k;//
   int a=n/2;
   int b=a/(k+1);
   a=b*k;
   cout << b <<" "<<a<<" "<<n-b-a;
   return 0;
}