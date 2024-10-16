#include<stdio.h>
typedef struct node{
    int y;
    int m;
    int d;
}node;
node stu[100];
void swap(int a,int b){
    stu[a].y^=stu[b].y; stu[b].y^=stu[a].y; stu[a].y^=stu[b].y;
    stu[a].m^=stu[b].m; stu[b].m^=stu[a].m; stu[a].m^=stu[b].m;
    stu[a].d^=stu[b].d; stu[b].d^=stu[a].d; stu[a].d^=stu[b].d;
}
int main(){
    int t,i=0;
    scanf("%d",&t);
    while(i<t){
        scanf("%d %d %d",&stu[i].y,&stu[i].m,&stu[i].d);
        i++;
        // printf("%d\n",i);
    }
    for(int i=0; i<t; i++){
        for(int j=0; j<t; j++){
            if(stu[i].y==stu[j].y){
                if(stu[i].m==stu[j].m){
                    if(stu[i].d>stu[j].d) swap(i,j);
                }else if(stu[i].m>stu[j].m) swap(i,j);
            }else if(stu[i].y>stu[j].y) swap(i,j);
        }
    }
    // for(int i=0; i<t; i++){
    //     printf("%d-%d-%d\n",stu[i].y,stu[i].m,stu[i].d);
    // }
    printf("%d-%d-%d\n",stu[t-2].y,stu[t-2].m,stu[t-2].d);
    return 0;
}