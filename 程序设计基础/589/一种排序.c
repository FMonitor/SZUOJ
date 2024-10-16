#include<stdio.h>
typedef struct node{
    int l;
    int w;
    int h;
    int same;
}node;
node box[1005];
void swap(int a,int b){
    box[a].l^=box[b].l; box[b].l^=box[a].l; box[a].l^=box[b].l;
    box[a].w^=box[b].w; box[b].w^=box[a].w; box[a].w^=box[b].w;
    box[a].h^=box[b].h; box[b].h^=box[a].h; box[a].h^=box[b].h;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,a=0;
        scanf("%d",&n);
        while(a<n){
            scanf("%d %d %d",&box[a].l,&box[a].w,&box[a].h);
            if(box[a].w<box[a].h){
                box[a].w^=box[a].h; 
                box[a].h^=box[a].w; 
                box[a].w^=box[a].h;
            }
            a++;
        } 
        // printf("%d\n",i);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                if(box[j].same || box[i].same) continue;
                if(box[i].l==box[j].l){
                    if(box[i].w==box[j].w){
                        if(box[i].h==box[j].h) box[j].same=1;
                        else if(box[i].h<box[j].h) swap(i,j);
                    }else if(box[i].w<box[j].w) swap(i,j);
                }else if(box[i].l<box[j].l) swap(i,j);
            }
        }
        // for(int i=0; i<n; i++){
        //     printf("%d-%d-%d %d\n",box[i].l,box[i].w,box[i].h,box[i].same);
        // }
        for(int i=0; i<n; i++){
            if(box[i].same!=1) printf("%d %d %d\n",box[i].l,box[i].w,box[i].h);
        }
    }
    return 0;
}