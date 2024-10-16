#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int x,y;
   cin >> x >> y;
   if(x>=-1 && x<=1 && y>=-1 && y<=1) cout << "yes";
   else cout << "no";
   return 0;
}