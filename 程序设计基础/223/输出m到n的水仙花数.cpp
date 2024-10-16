#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

bool v(int a){
   int b=pow(a/100,3)+pow(a/10%10,3)+pow(a%10,3);
   if(b==a) return 1;
   return 0;
}
signed main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int n,m;
   cin >> n >> m;
   for(int i=n; i<=m; i++){
      if(v(i)) cout << i << endl;
   }
   return 0;
}