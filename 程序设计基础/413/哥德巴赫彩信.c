#include<stdio.h>
#include<string.h>
#include<math.h>
int isprime(int x);
int main(){
   int m,ans=0;
   scanf("%d",&m);
   for(int i=2; i<; i++){
      if(isprime(i) && isprime(m-i))
         ans++;
   }
   printf("%d",ans);
   return 0;
}
int isprime(int x){
   if(x==1 || x==0)return 0;
   for(int i=2; i<x; i++){
      if(x%i==0) return 0;
   }
   return 1;
}
