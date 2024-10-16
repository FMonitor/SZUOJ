#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   string n;
   cin >> n;
   if(n.size()!=3) cout << "ERROR";
   else{
      int num=(n[0]-'0')*100+(n[1]-'0')*10+n[2]-'0';
      int a=n[0]-'0',b=n[1]-'0',c=n[2]-'0';
      if(a*a*a+b*b*b+c*c*c==num) cout <<"1";
      else cout << 0;
   }
   return 0;
}