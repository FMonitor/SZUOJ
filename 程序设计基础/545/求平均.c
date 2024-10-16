#include<stdio.h>
int main(){
    double arr[10000],sum;
    double *p=arr;
    while(scanf("%lf",p)){
        if(*p==0) break;
        sum+=*p;
        p++;
    }
    printf("%d %g",p-arr,sum/(p-arr));
    return 0;
}