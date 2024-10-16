#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char a[33],*p=a;
        scanf("%s",a);
        int cnt=0;
        while(*p!='\0'){
            cnt++;
            *p++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}