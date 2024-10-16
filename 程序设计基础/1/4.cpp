#include<stdio.h>
int main(){
	float r,h;
	scanf("%f %f",&r,&h);
	printf("C1=%.2f\n",2*3.14*r);
	printf("Sa=%.2f\n",3.14*r*r);
	printf("Sb=%.2f\n",4*3.14*r*r);
	printf("Va=%.2f\n",3.14*r*r*r*4/3);
	printf("Vb=%.2f\n",3.14*r*r*h);
	return 0;
}