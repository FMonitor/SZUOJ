#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

signed main(){
   double a,b,c;
   cin >> a >> b >> c;
   double d=b*b-4*a*c;
   if(a!=0)
      if(d<0) cout << "wa" << endl;
      else if(d>0){
         cout << "2" <<" "; 
         double x1=(-b-sqrt(d))/2/a;
         double x2=(-b+sqrt(d))/2/a;
         if(x1>x2) swap(x1,x2);
         cout << fixed<<setprecision(2)<<x1<<" "<<fixed<<setprecision(2)<<x2<< endl;
      }
      else{
         cout << "1 ";
         if(b==0) b=-b;
         cout << fixed<<setprecision(2)<<(-b)/2/a << endl;
      }
   if(a==0 && b!=0 && c!=0){
      cout << "1 " << fixed << setprecision(2) << -c/b;
   }
   if(a==0 && b==0 && c!=0) cout << "wa";
   if(a==0 && b==0 && c==0) cout << "inf";
   return 0;
}