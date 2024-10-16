#include<bits/stdc++.h>
using namespace std;
int main(){
   char s[10000]={'\0'};
   scanf("%s",&s);
   for(int i=0; i<strlen(s); i++){
      for(int j=i; j<strlen(s); j++){
         if(s[i]>s[j]) swap(s[i],s[j]);
      }
   }
   for(int i=0; i<strlen(s); i++){
      printf("%c",s[i]);
      while(s[i+1]==s[i]) i++;
   }
   return 0;
}