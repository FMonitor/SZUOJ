#include<stdio.h>
int main(){
    char *p[12]={
        "January","February","March",
        "April","May","June","July",
        "Aguest","September","October",
        "November","December"};
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        if(n>12||n<1) printf("error\n"); 
        else printf("%s\n",*(p+n-1));
    }
    return 0;
}
