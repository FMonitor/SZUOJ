#include<stdio.h>
int gcd(int a,int b);
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",gcd(a,b));
    }
    return 0;
}
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}