#include<bits/stdc++.h>
using namespace std;
int main(){
   double a,n,ans=0;
   cin >> a >> n;
   for(int i=1; i<=n; i++){
      ans+=a;
      a/=2;
      a=(int)((a*1000+5)/10) / 100.0;
      ans+=a;
   }
   ans-=a;
   cout <<fixed<< setprecision(2)<< ans << endl <<fixed <<setprecision(2)<< a;
   return 0;
}