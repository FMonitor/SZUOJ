#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        char ch;
        scanf("%d %c",&n,&ch);
        int c=2*n-2;
        int s=1;
        for(int i=1; i<=n; i++){
            for(int j=0; j<c; j++){
                printf(" ");
            }
            for(int j=0; j<s; j++){
                printf("%c",ch);
            }
            c-=2;
            s+=2;
            printf("\n");
        }
        if(t!=0)printf("\n");
    }
    return 0;
}