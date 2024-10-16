#include<stdio.h>  
#include<string.h>
int ans;
int arr[10000];
int n;
void cnt(int now,int c){
    // printf("%d %d\n",now,c);
    if(now==n){
        if(arr[now-1]!=arr[0] || n==1) ans++;
        // for(int i=0; i<n; i++){
        //     printf("%d ",arr[i]);
        // }
        // printf("\n");
        return;
    }
    arr[now]=c;
    if(c==1){
        cnt(now+1,2);
        cnt(now+1,3);
    }else if(c==2){
        cnt(now+1,1);
        cnt(now+1,3);
    }else{
        cnt(now+1,1);
        cnt(now+1,2);
    }
}
int main(){
    while(1){
        ans=0;
        if(scanf("%d",&n)==EOF)break;
        cnt(0,1);
        cnt(0,2);
        cnt(0,3);
        printf("%d\n",ans/2);
    }

    return 0;
}
