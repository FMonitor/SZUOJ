#include<stdio.h>
#include<string.h>
#include<math.h>
int arr[4];
void check(char c);
int main(){
   char s[30000];
   gets(s);
   for(int i=0; i<strlen(s); i++){
      check(s[i]);
   }
   printf("%d %d %d %d",arr[0],arr[1],arr[2],arr[3]);
   return 0;
}
void check(char c){
   if(c>='a' && c<='z' || c>='A' && c<='Z'){
      arr[0]++;
   }else if(c>='0' && c <='9'){
      arr[1]++;
   }else if(c==' '){
      arr[2]++;
   }else{
      arr[3]++;
   }
}
