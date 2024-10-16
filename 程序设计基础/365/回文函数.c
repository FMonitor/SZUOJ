#include<stdio.h>
#include<string.h>
int isPalindrome(char s[]);
int main(){
   int t;
   scanf("%d",&t);
   while(t--){
      char a[10000];
      scanf("%s",&a);
      if(isPalindrome(a)){
         printf("Yes\n");
      }else{
         printf("No\n");
      }
   }
   return 0;
}
int isPalindrome(char s[]){
   int len=strlen(s);
   int i=len/2;
   if(len==1) return 1;
   for(i; i>=0; i--){
      if(s[i]!=s[len-i-1]) return 0;
   }
   return 1;
}