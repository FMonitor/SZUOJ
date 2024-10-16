#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a=0;
	int c,b;
	cin >> c >> b;
	a+=pow(10,c);
	a+=b;
	cout <<"10^"<<c<<"+"<<b<<" = "<< a << endl;
	return 0;
}