#include<stdio.h>
#include<math.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		double s,a,b,c;
		scanf("%lf %lf %lf",&a,&b,&c);
		s=a+b+c;
		s/=2;
		double ans=sqrt(s*(s-a)*(s-b)*(s-c));
		printf("%.2lf\n",ans);
	}
	return 0;
}