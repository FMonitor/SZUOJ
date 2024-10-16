#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<vector>
using namespace std;
int main(){
   int t;
   cin >> t;
   while(t--){
      int n,k,ans=0;
      cin >> n >> k;
      for(int i=1; i<=k; i++){
         ans+=pow(n,i);
      }
      cout << ans << endl;
   }
   return 0;
}