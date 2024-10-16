#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<vector>
using namespace std;
int main(){
   int t,now,n,ans=0;
   cin >> t >> n;
   now=t;
   for(int i=1; i<=n; i++){
      ans+=now;
      now=now*10+t;
   }
   cout << ans;
   return 0;
}