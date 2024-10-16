#include<stdio.h>
#include<string.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char str[10000];
        char key[10000];
        char crypt[10000];
        scanf("%s",&str);
        scanf("%s",&key);
        char *p=str,*q=key,*s=crypt;
        for(int i=0,j=0; i<strlen(str); i++,j++){
            if(j==strlen(key)) j=0;
            *(s+i)=*(p+i)+*(q+j)-'0';
            if(*(s+i)>'Z' && *(s+i)<'a' || *(s+i)>'z') *(s+i)-='Z'-'A'+1;
            printf("%c",*(s+i));
        }
        printf("\n");
    }
    return 0;
}