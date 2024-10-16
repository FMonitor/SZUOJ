#include<stdio.h>

int arr[105];
void check(int t){
    int i=0;
    while(arr[i]<arr[i+1] && i<t-1){
        i++;
    }
    while(arr[i]==arr[i+1] && i<t-1){
        i++;
    }
    while(arr[i]>arr[i+1] && i<t-1){
        i++;
    }
    if(i==t-1)
        printf("YES\n");
    else printf("NO\n");
    return;
}
int main(){
    while(1){
        int t;
        if(scanf("%d",&t)==EOF) break;
        else{
            for(int i=0; i<t; i++){
                scanf("%d",&arr[i]);
            }
            check(t);
        }
    }
    return 0;
}