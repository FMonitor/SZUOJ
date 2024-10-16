#include<stdio.h>
int main()
{
	int min, len1, len2, len, a[100], b[100], tmp, i, j;
	scanf("%d", &len1);
	for (i = 0; i<len1; i++)
		scanf("%d", &a[i]);
	scanf("%d", &len2);
	for (i = 0; i<len2; i++)
		scanf("%d", &b[i]);
/********** Write your code here! **********/
	int c[200];
	len=len1+len2;
	int index1=0,index2=0,index3=0;
	while(index1<len1 && index2<len2){
		if(a[index1]>b[index2]){
			c[index3++]=b[index2++];
		}else{
			c[index3++]=a[index1++];
		}
	}
	if(index1==len1){
		while(index2<len2){
			c[index3++]=b[index2++];
		}
		for(int k=0; k<index3; k++){
			b[k]=c[k];
		}
	}else{
		while(index1<len1){
			c[index3++]=a[index1++];
		}
		for(int k=0; k<index3; k++){
			b[k]=c[k];
		}
	}



/*******************************************/
	for (i = 0; i<len; i++)
		printf("%d ", b[i]);
	return 0;
}