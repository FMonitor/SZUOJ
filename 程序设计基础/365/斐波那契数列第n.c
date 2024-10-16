#include<stdio.h>
#include<string.h>
void fib(int a,int arr[]);
int main(){
   int t;
   int arr[10000];
   arr[0]=0;
   arr[1]=1;
   scanf("%d",&t);
   for(int i=2; i<=t; i++){
      fib(i,arr);
   }
   printf("%d",arr[t]);
   return 0;
}
void fib(int a,int arr[]){
   arr[a]=arr[a-1]+arr[a-2];  
}
