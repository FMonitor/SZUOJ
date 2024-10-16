#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   char n;
   cin >> n;
   n+=4;
   if(n>'Z') n-='Z'-'A'+1;
   cout << n;
   return 0;
}