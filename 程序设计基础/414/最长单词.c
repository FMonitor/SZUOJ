#include<stdio.h>
#include<string.h>
int arr[105];
int max(int a,int b){
    return a>b?a:b;
}
void MaxLenWord(char s[]){
    char word[100][100];
    int len[100],maxl=0;
    int i=0,j=0,k=0,ans=0;
    while(i<strlen(s)){
        word[j][k]=s[i];
        if(s[i]==' ' || s[i]=='\n'){
            word[j][k]='\0';
            j++;
            k=-1;
        }
        k++;
        i++;
    }
    for(int a=0; a<=j; a++){
        // printf("%s\n",word[a]);
        len[a]=strlen(word[a]);
        if(maxl==len[a]) ans++;
        else if(maxl<len[a]) ans=0;
        maxl=max(maxl,len[a]);
    }
    for(int a=0; a<=j; a++){
        if(len[a]==maxl){
            printf("%s",word[a]);
            if(ans!=0) printf(" ");
            ans--;
        }
    }
}
int main(){
    int t;
    scanf("%d\n",&t);
    while(t--){
        char ch[10000];
        gets(ch);
        MaxLenWord(ch);
        if(t!=0) printf("\n");
    }
    return 0;
}