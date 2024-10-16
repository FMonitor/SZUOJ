#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

signed main(){
   double h,r,v,d;
   cin >> h >> r >> v >> d;
   if(r<h) cout << "sad";
   else{
      double l=sqrt(r*r-h*h);
      if((d-l)<0) cout << "0.00";
      else cout << fixed << setprecision(2)<< (d-l)/v;
      return 0;
   }
}