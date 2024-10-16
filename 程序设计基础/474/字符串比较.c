#include<stdio.h>  
#include<string.h>
void cmp(char* S,char* T);
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        char a[100],b[100];
        scanf("%s",&a);
        scanf("%s",&b);
        cmp(a,b);
    }
    return 0;
}
void cmp(char* S,char* T){
    int ans=0;
    if(strlen(S)>strlen(T)){
        printf("1\n");
        return;
    }else if(strlen(S)<strlen(T)){
        printf("-1\n");
        return;
    }
    for(int i=0; i<strlen(S); i++){
        if(*(S+i)>*(T+i)) ans++;
        else if(*(S+i)<*(T+i)) ans--;
    }
    if(ans>0) printf("1\n");
    else if(ans==0) printf("0\n");
    else printf("-1\n");
    return;
}