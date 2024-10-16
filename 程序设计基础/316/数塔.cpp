#include<stdio.h>

int arr[104][104],dp[104][104];
int max(int a,int b) {return (a>b ? a:b);}
int main(){
    int t;
    scanf("%d",&t);
    while(t--)
    {int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            if(j==1) dp[i][j]=dp[i-1][j]+arr[i][j];
            else if(j==i) dp[i][j]=dp[i-1][j-1]+arr[i][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+arr[i][j];
        }
    }
    int maxn=0;
    for(int i=1; i<=n; i++) maxn=max(maxn,dp[n][i]);
    printf("%d",maxn);
    return 0;}
}