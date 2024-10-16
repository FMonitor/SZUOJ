#include<stdio.h>
int main(){
    int d,n=1,m=100000;
    int sum=0;
    scanf("%d",&d);
    for(int i=0; i<d; i++){
        sum+=n;
        n*=2;
    }
    printf("%d\n%d\n",d*m,sum);
    return 0;
}