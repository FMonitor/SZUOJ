#include<stdio.h>
#include<string.h>
void cut(int t,char s[],int size);
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char s[1005];
        scanf("%s",&s);
        cut(0,s,strlen(s));
        if(t!=0) printf("\n");
    }
    return 0;
}
void cut(int t,char s[],int size){
    if(strlen(s)%2==1){
        printf("%d",size);
        return;
    }
    int mid=size/2-1;
    int flag=0;
    for(int i=0; i<=mid; i++){
        // printf("%c %c\n",s[i],s[strlen(s)-1-i]);
        if(s[i]!=s[size-1-i]){
            printf("%d",size);
            flag=1;
            return;
        }
    }
    if(!flag) cut(t+1,s,mid+1);
    return;
}