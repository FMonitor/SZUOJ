#include<bits/stdc++.h>
using namespace std;
int arr[1000005];
int main(){
   int l,m;
   while(cin>>l){
      if(l==EOF) break;
      cin >> m;
      int maxn=0,minx=0;
      for(int i=0; i<m; i++){
         cin >> arr[i];
         maxn=max(max(l-arr[i],arr[i]),maxn);
         minx=max(min(l-arr[i],arr[i]),minx);
      }
      cout << minx <<" "<<maxn<<endl;
   }
   return 0;
}