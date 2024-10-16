#include<stdio.h>

int main(){
    int t;
    scanf("%d\n",&t);
    while(t--){
        char s[1000];
        char *p=s;
        scanf("%s",s);
        int flag=1;
        // if(t!=0) getchar();
        int i=0,sum=0;
        while(*(p+i)!='\0'){
            // printf("%c ",*p);
            if(*(p+i)<'0' || *(p+i)>'9'){
                printf("-1\n");
                flag=0;
                break;
            }
            sum=sum*10+*(p+i)-'0';
            i++;
        }
        if(flag)
            printf("%d\n",sum);
    }
    return 0;
}