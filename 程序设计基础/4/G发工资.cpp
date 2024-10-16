#include<iostream>
using namespace std;
int main(){
	int a;
	cin >> a;
	cout << a/100<<" ";
	a%=100;
	cout << a/50<<" ";
	a%=50;
	cout << a/20<<" ";
	a%=20;
	cout << a/10<<" ";
	a%=10;
	cout << a/5 <<" ";
	a%=5;
	cout << a<<" ";
	return 0;
}
