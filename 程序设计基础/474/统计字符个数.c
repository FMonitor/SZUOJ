#include<stdio.h>  
#include<string.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
    char a[100];
    int ans=0;
    scanf("%s",&a);
    char* p=a;
    while(*p!='\0'){
        ans++;
        p++;
    }
    printf("%d\n",ans);
    }
    return 0;
}
