#include<stdio.h>  
void output(int* p);
int n,m;
int main(){
    scanf("%d %d",&n,&m);
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0; j<m; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    output(arr);
    return 0;
}
void output(int* p){
    int maxn=0;
    int minx=1e9;
    for(int i=0; i<m*n; i++){
        maxn=*(p+i)>maxn ? *(p+i) : maxn;
        minx=*(p+i)<minx ? *(p+i) : minx;
    }
    printf("%d\n%d",maxn,minx);
}