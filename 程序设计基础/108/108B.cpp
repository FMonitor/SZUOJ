#include<bits/stdc++.h>
int main(){
	int a,b,c;
	scanf("%X %X %X",&a,&b,&c);
	printf("%02X%02X%02X",255-a,255-b,255-c);
	return 0;
}