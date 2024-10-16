#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int n=0;
char in[10000][1000];
int pow(int a){
   return a==0?1:10*pow(a-1);
}
double strToDouble(char str[]){
   int len=strlen(str),s=1,out[10],k=-2,cnt=0;
   double fi = 0;
   if(str[0]=='-') s=-1;
   else if(str[0]=='\0') return 0.0;
   for(int i = 0; i < len; i++){
      if(str[i] >= '0' && str[i] <= '9'){
         out[cnt] = str[i] - '0';
         cnt++;
      }else if(str[i] == '.'){
         if(k == -2) k=cnt-1;
      }
   }
   if(k == -2) k=count-1;
   if(cnt==0) return 0.0;
   int ao=0,sta=0;
   for(int i=0;i<cnt;i++){
      if(i-ao>=6){
         if(out[i] >= 5){
            fi += 1.0 / quipow(i-1-k);
            break;
         }
      }
      if(sta == 0){
         if(out[i] == 0) ao++;
         else{
            sta=1;
            if(i<=k) fi+=out[i]*quipow(k-i);
            else fi+=out[i]*1.0/quipow(i-k);
         }   
      }else if(sta==1){
         if(i<=k) fi+=out[i]*quipow(k-i);
         else fi+=out[i]*1.0/quipow(i-k);
      }
   }
   return s*fi;
}
int main(){
   while(gets(in[n])!=NULL){
      n++;
   }
   int tmp;
   for(int i=0; i<n; i++){
      tmp=strToDouble(in[i]);
      if(tmp == strToDouble(in[i])) printf("%d\n",tmp);
      else printf("%g\n",strToDouble(in[i]));
   }
   return 0;
}