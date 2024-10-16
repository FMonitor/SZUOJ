#include<stdio.h>
int main(){
	int a,b;
	char c;
	scanf("%x%c%x",&a,&c,&b);
	if(c=='+'){
		printf("%o",a+b);
	}else{
		printf("%o",a-b);
	}
	return 0;
}
