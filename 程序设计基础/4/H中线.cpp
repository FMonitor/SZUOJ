#include<bits/stdc++.h>
using namespace std;
int main(){
	int a;
	double b,c;
	while(cin >> a){
		cin >> b >> c;
		double d=a;
		double s=sqrt((d+b+c)*(b+c-d)*(b+d-c)*(d+c-b))/3;
		if(s>0)
			cout <<fixed<<setprecision(3)<< s << endl;
		else
			cout << -1 <<endl;
	}
	return 0;
}
