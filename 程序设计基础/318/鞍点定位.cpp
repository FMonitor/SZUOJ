#include<bits/stdc++.h>
using namespace std;
int main(){
   int t;
   cin >> t;
   while(t--){
      int a,b;
      cin >> a >> b;
      int arr[a][b];
      int c[a][b];
      memset(c,0,sizeof(c));
      for(int i=0; i<a; i++){
         int mi=0;
         for(int j=0; j<b; j++){
            cin >> arr[i][j];
            mi=max(mi,arr[i][j]);
         }
         for(int j=0; j<b; j++){
            if(arr[i][j]==mi){
               c[i][j]++;
            }
         }
      }
      for(int j=0; j<b; j++){
         int mi=1e9;
         for(int i=0; i<a; i++){
            mi=min(arr[i][j],mi);
         }
         for(int i=0; i<a; i++){
            if(arr[i][j]==mi){
               c[i][j]++;
            }
         }
      }
      bool flag=0;
      for(int i=0; i<a; i++){
         for(int j=0; j<b; j++){
            if(c[i][j]==2){
               printf("%d %d\n",i,j);
               flag=1;
            }
         }
      }
      if(!flag) printf("-1\n");
   }
   return 0;
}