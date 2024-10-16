#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

signed main(){
   int a,b,c,x,y,z;
   scanf("%d/%d/%d",&a,&b,&c);
   scanf("%d/%d/%d",&x,&y,&z);
   if((a+b+c)%2==(x+y+z)%2) cout <<"YES"<<endl;
   else cout << "NO";
   return 0;
}