#include<stdio.h>
int main(){
	float r,h;
	scanf("%f %f",&r,&h);
	printf("C1=%.2f",2*3.14*r);
	printf("Sa=%.2f",3.14*r*r);
	printf("Sb=%.2f",4*3.14*r*r);
	printf("Va=%.2f",4/3*3.14*r*r*r);
	printf("Vb=%.2f",3.14*r*r*h);
	return 0;
}