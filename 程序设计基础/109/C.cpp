#include<stdio.h>
int main(){
	int a,b,c,x,y,z;
	scanf("%d:%d:%d",&a,&b,&c);
	scanf("%d:%d:%d",&x,&y,&z);
	a-=x;
	b-=y;
	c-=z;
	if(c<0){
		c+=60;
		b--;
	}
	if(b<0){
		b-=60;
		a--;
	}
	printf("%d:%d:%d",a,b,c);
	return 0;
}
