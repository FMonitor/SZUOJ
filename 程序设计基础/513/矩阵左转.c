#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    getchar();
    while(t--){
        // printf("!%d!\n",t);
        int arr[2][3];
        for(int i=0; i<2; i++){
            for(int j=0; j<3; j++)
            scanf("%d",&arr[i][j]);
            getchar();
        }
        int *p=arr;
        printf("%d %d \n",*(p+2),*(p+5));
        printf("%d %d \n",*(p+1),*(p+4));
        printf("%d %d \n",*p,*(p+3));
    }
    return 0;
}