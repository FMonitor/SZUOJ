#include<bits/stdc++.h>
using namespace std;
int main(){
   int t;
   scanf("%d",&t);
   while(t--){
      char a[100000]={0};
      scanf("%s",&a);
      fflush;
      int i=0;
      while(a[i]!='\0'){
         if(a[i]>='A' && a[i]<='Z'){
            printf("%c",a[i]+'a'-'A');
         }else if(a[i]>='a' && a[i]<='z'){
            printf("%c",a[i]-'a'+'A');
         }else{
            printf("%c",a[i]);
         }
         i++;
      }printf("\n");
   }
   return 0;
}