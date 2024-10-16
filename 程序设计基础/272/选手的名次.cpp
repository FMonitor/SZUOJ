#include<bits/stdc++.h>
using namespace std;
int arr[5];
void check(int a,int b,int c,int d,int e){
   if(a==3 && b!=2 || b==2 && a!=3){
      if(b==2 && e!=4 || b!=2 && e==4){
         if(c==1 && d!=2 || c!=1 && d==2){
            if(c==5 && d!=3 || c!=5 && d==3){
               if(e==4 && a!=1 || e!=4 && a==1){
                  arr[0]=a;
                  arr[1]=b;
                  arr[2]=c;
                  arr[3]=d;
                  arr[4]=e;
                  // cout << a <<" "<<b <<" "<<c<<" "<<d<<" "<<e<<endl;
               }
            }
         }
      }
   }
   
}
int main(){
   
   for(int i=1; i<=5; i++){
      for(int j=1;j<=5; j++){
         if(j==i) continue;
         for(int k=1;  k<=5; k++){
            if(k==i || k==j) continue;
            for(int l=1;  l<=5; l++){
               if(l==k || l==i || l==j) continue;
               for(int m=1; m<=5; m++){
                  if(m==k || m==l || m==j || m==i) continue;
                  
                  check(i,j,k,l,m);
               }
            }
         }
      }
   }
   int n;
   cin >> n;
   while(n--){
      bool flag=0;
      int num[5];
      for(int i=0; i<5; i++){
         char c;
         cin >> c;
         num[c-'A']=i+1;
         // cout << num[i];
      }
      for(int i=0; i<5; i++){
         if(num[i]!=arr[i]){
            flag=1;
            break;
         }
      }
      if(flag) cout << "NO" << endl;
      else cout << "YES" << endl;
   }
   return 0;
}