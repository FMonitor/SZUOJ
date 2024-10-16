#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	int a;
	scanf("%d",&a);
	for(int i=0; i<a; i++){
		int x,y,z,s=0;
		scanf("%d %d %d",&x,&y,&z);
		s+=2*x*y;
		s+=2*x*z;
		s+=2*y*z;
		printf("%d\n",s);
	}
	return 0;
}