#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        char ch;
        scanf("%d %c",&n,&ch);
        for(int i=1; i<=n; i++){
            for(int j=n; j>i; j--){
                printf(" ");
            }
            for(int j=1; j<=i; j++){
                printf("%c",ch);
            }
            printf("\n");
        }
        if(t!=0)printf("\n");
    }
    return 0;
}