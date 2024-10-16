#include<stdio.h>
int main(){
	double a;
	scanf("%lf",&a);
	if(a<0)
	 	a*=-1;
	printf("%.2lf",a);
	return 0;
}
