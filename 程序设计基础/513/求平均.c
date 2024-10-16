#include<stdio.h>
int main(){
    double n,arr[1000],total=0;
    int i=0;
    while(scanf("%lf",&n)!=EOF){    
        if(n==0) break;
        *(arr+i)=n;
        total += *(arr+i);
        i++;
    }
    printf("%d %g",i,total/(i));
    return 0;
}