#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int *p=(a+n/2);
        int n1,n2,n3;
        scanf("%d",&n1);
        *p--;
        printf("%d ",*p);
        *p++;
        *p++;
        printf("%d\n",*p);
        *p--;
        printf("%d",*(a+n1-1));
        if(t!=0) printf("\n");
    }
    return 0;
}