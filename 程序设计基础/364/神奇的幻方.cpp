#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int arr[40][40];
int cnt,t;
void out(){
    for(int i=1; i<=t; i++){
        for(int j=1; j<=t; j++){
            printf("%d",arr[i][j]);
            if(j!=t) printf(" ");
        }
        if(i!=t) printf("\n");
    }
    exit(0);
}
void put(int x,int y){
    if(cnt==t*t) out();
    cnt++;
    arr[x][y]=cnt;
    if(x==1 && y!=t) put(t,y+1);
    else if(y==t && x!=1) put(x-1,1);
    else if(x==1 && y==t) put(2,t);
    else if(!arr[x-1][y+1]) put(x-1,y+1);
    else put(x+1,y);
}
int main(){
    scanf("%d",&t);
    put(1,t+1>>1);
    return 0;
}