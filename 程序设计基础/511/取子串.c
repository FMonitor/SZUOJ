#include<stdio.h>
#include<string.h>
char *substr(char *s,int startloc, int len);
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char s[500];
        scanf("%s",s);
        int begin,len;
        scanf("%d %d",&begin,&len);
        substr(s,begin,len);
        if(t!=0) printf("\n");
    }
    return 0;
}
char *substr(char *s,int startloc, int len){
    if(startloc>strlen(s)){
        printf("NULL");
        return NULL;
    }
    for(int i=startloc-1; i<=startloc+len-2; i++){
        if(*(s+i)=='\0') break;
        printf("%c",*(s+i));
    }
}