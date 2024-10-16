#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int n;
char in[100][2][100];
int cmp(char* a, char* b){
    int out = 0;
    int al = strlen(a), bl = strlen(b);
    if(al != bl){
        if(al > bl){
            return 1;
        }else{
            return -1;
        }
    }else{
        for(int i=0; i<al; i++){
            if(a[i]>b[i]){
                out+=1;
            }else if(a[i]<b[i]){
                out-=1;
            }
        }
        return out;
    }
}
int sgn(int a){
    if(a>0){
        return 1;
    }else if(a==0){
        return 0;
    }else if(a<0){
        return -1;
    }
}
int main()
{
    scanf("%d",&n);
    getchar();
    for(int i=0; i<n; i++){
        gets(in[i][0]);
        gets(in[i][1]);
    }
    for(int i = 0; i < n; i++){
        printf("%d\n",sgn(cmp(in[i][0],in[i][1])));
    }
    return 0;
}