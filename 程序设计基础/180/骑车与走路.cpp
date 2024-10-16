#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   double n;
   cin >> n;
   double eps=1e-8;
   double bike=n/3+50;
   double walk=n/1.2;
   if(fabs(bike-walk)<eps){
      cout << "All";
   }else if(bike<walk) cout << "Bike";
   else cout << "Walk";
   return 0;
}