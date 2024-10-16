#include<stdio.h>
#include<string.h>
typedef struct node{
    char id[100];
    char a[100];
    char b[100];
    char c[100];
}node;
int cmp(char s1[],char s2[]){
    double l1=strlen(s1);
    double l2=strlen(s2);
    double same=0;
    for(int i=0; i<(strlen(s1)<strlen(s2)?strlen(s1):strlen(s2)); i++){
        if(s1[i]==s2[i]) same++;
    }
    // printf("%g %g %g\n",same,0.9*l1,0.9*l2);
    if(same>0.89*l1 || same>0.89*l2){
        // printf("?");
        return 1;
    }
    return 0;
}
void check(node *a,node *b){
    int flag=0;
    // printf("---%s %s %s\n",a->a,a->b,a->c);
    if(cmp(a->a,b->a) || cmp(a->b,b->b) || cmp(a->c,b->c)){
        flag=1;
        printf("%s %s",a->id,b->id);
        if(cmp(a->a,b->a)) printf(" 1");
        if(cmp(a->b,b->b)) printf(" 2");
        if(cmp(a->c,b->c)) printf(" 3");
    }
    if(flag) printf("\n");
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
            check(paper+j,paper+k);
        }
    }
    return 0;
}