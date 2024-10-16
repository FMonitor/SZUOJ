#include<stdio.h>
void get(int a,int b){
    int maxn=0;
    int minx=1000000;
    int arr[a][b];
    int *p=arr[0];
    // int c;
    for(int i=0; i<a*b; i++){
            scanf("%d",p+i);
            // scanf("%d",&c);
            if(i!=a*b-1) getchar();
            maxn=maxn> *(p+i) ? maxn: *(p+i);
            minx=minx< *(p+i) ? minx: *(p+i);
    }
    printf("%d\n%d",maxn,minx);
}
int main(){
    int a,b;
    scanf("%d %d\n",&a,&b);
    get(a,b);
    return 0;
}