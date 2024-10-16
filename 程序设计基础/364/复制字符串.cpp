#include<stdio.h>
#include<string.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char a[22],b[22];
        scanf("%s",&a);
        scanf("%s",&b);
        for(int i=0; i<strlen(b); i++){
            a[i]=b[i];
        }
        a[strlen(b)]=0;
        printf("%s\n",a);
    }
    return 0;
}