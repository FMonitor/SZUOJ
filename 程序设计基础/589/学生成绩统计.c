#include<stdio.h>
#include <string.h>
typedef struct node{
    int id;
    char name[10];
    double a;
    double b;
    double c;
}node;
node stu[100];
int main(){
    int t,i=0;
    scanf("%d",&t);
    while(i<t){
        scanf("%d %s %lf %lf %lf",&stu[i].id,&stu[i].name,&stu[i].a,&stu[i].b,&stu[i].c);
        i++;
        // printf("%d\n",i);
    }
    node best;
    best.a=0;
    best.b=0;
    best.c=0;
    double sum=0;
    int ca=0,cb=0,cc=0;
    for(int j=0; j<t; j++){
        if((stu[j].a+stu[j].b+stu[j].c)>(best.a+best.b+best.c)){
            // printf("%s\n",stu[j].name);
            strcpy(best.name,stu[j].name);
        }
        best.a=stu[j].a>best.a ? stu[j].a:best.a;
        best.b=stu[j].b>best.b ? stu[j].b:best.b;
        best.c=stu[j].c>best.c ? stu[j].c:best.c;
    }
    sum+=best.a;
    sum+=best.b;
    sum+=best.c;
    for(int i=0; i<t; i++){
        printf("%d %s %.2lf %.2lf %.2lf ",stu[i].id,stu[i].name,stu[i].a,stu[i].b,stu[i].c);
        printf("%.2lf\n",(stu[i].a+stu[i].b+stu[i].c)/3);
    }
    printf("%s %.2lf\n",best.name,sum/3);
    return 0;
}