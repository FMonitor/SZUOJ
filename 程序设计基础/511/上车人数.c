#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int arr[10000];
int up[10000];
int off[10000];
int a,n,m,x;
int search(int i,int now);
int main(){
    scanf("%d %d %d %d",&a,&n,&m,&x);
    int i=0;
    while(++i){
        search(i,1);
        // system("pause");
    }
    return 0;
}
int search(int i,int now){
    // printf("%d %d\n",i,now);
    if(now==n){
        // printf("%d\n",arr[now-1]);
        if(arr[now-1]==m){
            printf("%d",arr[x]);
            exit(0);
        }else return 0;
    }
    if(now==1){
        up[now]=a;
        off[now]=0;
        arr[now]=a;
        search(i,now+1);
    }else if(now==2){
        up[now]=i;
        off[now]=i;
        arr[now]=a;
        search(i,now+1);
    }else{
        up[now]=up[now-1]+up[now-2];
        off[now]=up[now-1];
        arr[now]=arr[now-1]+up[now]-off[now];
        search(i,now+1);
    }
    return 0;
}
