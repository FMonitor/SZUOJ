#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	double a,c;
	int b;
	cin >> a >> b >> c;
	cout << fixed << setprecision(6)<<a+b%3*(int)(a+c)%2/4;
	return 0;
}
