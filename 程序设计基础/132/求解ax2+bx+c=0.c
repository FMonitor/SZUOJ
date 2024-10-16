#include<stdio.h>
#include<math.h>
int main(){
   double a,b,c;
   scanf("%lf %lf %lf",&a,&b,&c);
   double d=b*b-4*a*c;
   if(d>0){
      printf("x1=%.3lf x2=%.3lf",(-b+sqrt(d))/2/a,(-b-sqrt(d))/2/a);
   }else if(d==0){
      printf("x1=%.3lf x2=%.3lf",-b/2/a,-b/2/a);
   }else{
      printf("x1=%.3lf+%.3lfi x2=%.3lf-%.3lfi",-b/2/a,sqrt(-d)/2/a,-b/2/a,sqrt(-d)/2/a);
   }
   return 0;
}