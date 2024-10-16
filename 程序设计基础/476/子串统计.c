#include<stdio.h>
#include<string.h>
int main(){
    char a[23];
    char b[23];
    scanf("%s",a);
    scanf("%s",b);
    char *pa=a;
    char *pb=b;
    int cnt=0;
    for(int i=0; i<strlen(a); i++){
        int flag=0;
        for(int j=0; j<strlen(b); j++){
            if(*(pa+i+j)!=*(pb+j)){
                flag=1;
                break;
            }
        }
        if(!flag) cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}