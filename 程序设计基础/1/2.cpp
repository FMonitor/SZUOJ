#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int arr[n],ave=0;
		for(int i=0; i<n; i++){
			scanf("%d",&arr[i]);
			ave+=arr[i];
		}
		ave/=n;
		int cnt=0;
		for(int i=0; i<n; i++){
			if(arr[i]>ave) cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;  
}