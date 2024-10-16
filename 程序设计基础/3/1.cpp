#include<stdio.h>
#include<math.h>
int main(){
	double r;
	int n;
	scanf("%lf,%d",&r,&n);
	printf("Area=%.2lf\n",n*r*r*sin(2*3.1415926/n)/2);
	return 0;
}
