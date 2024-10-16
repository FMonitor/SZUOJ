#include<stdio.h>
#include<string.h>
int t, ind;

int Substring(char str1[],char str2[],int index);
int main(){
    scanf("%d", &t);
    fflush(stdin);
    t*=2;
    while(t--){
        char str1[2000];
        char str2[2000];
        memset(str1,0,sizeof(str1));
        memset(str2,0,sizeof(str2));
        gets(str1);
        fflush(stdin);
        scanf("%d", &ind);
        fflush(stdin);
        if(t%2==0){
            Substring(str1,str2,ind);
        }
    }
    return 0;
}
int Substring(char str1[],char str2[],int index){
    if(index<0||strlen(str1)<=index)
    {
        printf("IndexError\n");
        return 0;
    }
 	int i;
    for (i=index;i<strlen(str1);i++)
    {
        str2[i-index] = str1[i];
    }
  	str2[i-index]='\0';
    printf("%s\n", str2);
    return 1;
}