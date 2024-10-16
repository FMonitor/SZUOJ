#include<stdio.h>
#include<string.h>
struct node{
    char id[100];
    char a[100];
    char b[100];
    char c[100];
};
int cmp(char s1[],char s2[]){
    int l1=strlen(s1);
    int l2=strlen(s2);
    double same=0;
    for(int i=0; i<(strlen(s1)<strlen(s2)?strlen(s1):strlen(s2)); i++){
        if(s1[i]==s2[i]) same++;
    }
    if(same>=0.9*strlen(s1) || same>=0.9*strlen(s2)){
        return 1;
    }
    return 0;
}
void check(node a,node b){
    // printf("%s %s %s\n",a.a,a.b,a.c);
    if(cmp(a.a,b.a) || cmp(a.b,b.b) || cmp(a.c,b.c)){
        printf("%s %s ",a.id,b.id);
        if(cmp(a.a,b.a)) printf("1\n");
        if(cmp(a.b,b.b)) printf("2\n");
        if(cmp(a.c,b.c)) printf("3\n");
    }
    return;
}
int main(){
    int t;
    scanf("%d",&t);
    node paper[t];
    int i=0;
    while(i<t){
        scanf("%s",&paper[i].id);
        // printf("!%s\n",paper[i].id)
        scanf("%s",&paper[i].a);
        scanf("%s",&paper[i].b);
        scanf("%s",&paper[i].c);
        i++;
        // printf("?\n");
    }
    for(int j=0; j<t; j++){
        for(int k=j+1; k<t; k++){
            // printf("---%s %s---\n",paper[j].id,paper[k].id);
            check(paper[j],paper[k]);
        }
    }
    return 0;
}