#include<stdio.h>
#include<string.h>
int comm(int a);
int main(){
   int t;
   scanf("%d",&t);
   while(t--){
      int a,b;
      scanf("%d %d",&a,&b);
      if(comm(a)==b && comm(b)==a && a!=b){
         printf("YES\n");
      }else{
         printf("NO\n");
      }
   }
   return 0;
}
int comm(int a){
   int ans=0;
   for(int i=2; i<a; i++){
      if(a%i==0) ans+=i;
   }
   return ans+1;
}
