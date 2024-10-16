#include <stdio.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	
int main() {
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	double sq=sqrt(b*b-4*a*c);
	double a1=(-b+sq)/2/a;
	double a2=(-b-sq)/2/a;
	printf("x1=%.2lf x2=%.2lf",a1,a2);
	return 0;
}