#include<stdio.h>
#include<string.h>
int main(){
    char c1[10];
    char c2[10];
    char c3[10];
    int t;
    int a1,b1;
    int a2,b2;
    int a3,b3;
    scanf("%d\n",&t);
    while(t--){    
        scanf("%s\n%s\n%s\n",c1,c2,c3);
        scanf("%d %d\n",&a1,&b1);
        scanf("%d %d\n",&a2,&b2);
        if(t!=0) scanf("%d %d\n",&a3,&b3);
        else scanf("%d %d",&a3,&b3);
        char *p= new char[30];
        int len=0;
        for(int i=a1-1; i<b1; i++){
            *(p+len)=c1[i];
            len++;
            printf("%c",c1[i]);
        }
        for(int i=a2-1; i<b2; i++){
            *(p+len)=c2[i];
            len++;
            printf("%c",c2[i]);
        }
        for(int i=a3-1; i<b3; i++){
            *(p+len)=c3[i];
            len++;
            printf("%c",c3[i]);
        }
        printf("\n");
        // for(int i=0; i<strlen(p); i++) printf("%c",p[i]);
        // printf("?\n");
        // printf("%s\n",c1);
    }
    return 0;
}