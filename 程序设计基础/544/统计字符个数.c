#include<stdio.h>

int main(){
    int t;
    scanf("%d\n",&t);
    while(t--){
        char s[1000];
        char *p=s;
        scanf("%s",s);
        int i=0;
        while(*(p+i)!='\0'){
            i++;
        }
        printf("%d\n",i);
    }
    return 0;
}