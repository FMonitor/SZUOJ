#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int n;
   cin >> n;
   if(n>=90) cout <<"A";
   else if(n>=80&&n<90) cout << "B";
   else if(n>=70&&n<80) cout << "C";
   else if(n>=60&&n<70) cout << "D";
   else cout << "E";
   return 0;
}