#include<stdio.h>
int main(){
	char a;
	scanf("%c",&a);
	a+='a'-'A';
	printf("%c",a);
	return 0;
}