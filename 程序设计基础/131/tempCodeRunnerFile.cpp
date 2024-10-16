#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int x1,y1,x2,y2;
   cin >> x1 >> y1 >> x2 >> y2;
   int x,y;
   cin >> x >> y;
   if(x>=x1 && x<=x2 && y>=y2 && y<=y1) cout << "IN";
   else cout << "OUT";
   
   return 0;
}