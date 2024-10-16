#include<stdio.h>
#include<string.h>
int arr[105];
int fib(int a){
    if(a==1 || a==2) return 1;
    return fib(a-1)+fib(a-2);
}
int main(){
    int t;
    scanf("%d\n",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        printf("%d\n",fib(n));
    }
    return 0;
}