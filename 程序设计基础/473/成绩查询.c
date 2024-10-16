#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0; i<n; i++)
            scanf("%d",arr+i);
        int* p=arr+n/2;
        p--;
        printf("%d ",*p);
        p++;p++;
        printf("%d \n",*p);
        p--;
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        printf("%d %d %d \n",*(p-n/2+a-1),*(p-n/2+b-1),*(p-n/2+c-1));

    }
    return 0;
}