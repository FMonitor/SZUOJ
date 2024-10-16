#include<stdio.h>
#include<string.h>
void del_char(char s[],char del);
int main(){
   char ch,s[20000];
   scanf("%c\n",&ch);
   gets(s);
   del_char(s,ch);
   return 0;
}
void del_char(char s[],char del){
   for(int i=0; i<strlen(s); i++){
      if(s[i]==del) continue;
      printf("%c",s[i]);
   }
}