#include<stdio.h>
int main(){
    double a[10000];
    double sum=0;
    int i=0;
    while(1){
        scanf("%lf",(a+i));
        if(*(a+i)==0) break;
        sum+=*(a+i);
        i++;
        // printf("%d\n",p);
    }
    printf("%d %g",i,sum/i);
    return 0;
}