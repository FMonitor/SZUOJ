#include<stdio.h>
#include<string.h>
int isprime(int x);
int main(){
   int m,n,ans=0;
   scanf("%d %d",&m,&n);
   for(int i=m; i<=n; i++){
      if(isprime(i))
         ans+=i;
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
