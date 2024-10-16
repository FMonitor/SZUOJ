#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int a,b;
   char c;
   cin >> a >> b >> c;
   if(c=='+') cout << a+b;
   else if(c=='-') cout << a-b;
   else if(c=='*') cout << a*b;
   else if(c=='/'){
      if(b==0) cout <<"Divided by zero!";
      else cout << a/b;
   }
   else cout << "Invalid operator!";
   return 0;
}