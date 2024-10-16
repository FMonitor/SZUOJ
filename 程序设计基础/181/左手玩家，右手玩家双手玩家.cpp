#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int a,b,c;
   cin >>a >> b >> c;
   if(a+c<=b) cout << a+c+a+c;
   else if(b+c<=a) cout << b+c+b+c;
   else{
   while(c){
      if(a<b){
         a++;
         c--;
      }else if(a>b){
         b++;
         c--;
      }else if(a==b && c>=2){
         a++;
         b++;
         c-=2;
      }else break;
   }
   cout << a+b;
   }
   
   return 0;
}