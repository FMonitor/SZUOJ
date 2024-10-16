#include<iostream>
#include<cmath>
using namespace std;
bool flag;
bool isprime(long long a){
    if(a==1 || a==0) return 0;
	for(int i=2; i<=sqrt(a); i++){
		if(a%i==0){
			return 0;
		}
	}
    return 1;
}
bool back(int i){
	string num;
	while(i){
		num+=i%10+'0';
		i/=10;
	}
	for(int i=0; i<num.size()/2; i++){
		if(num[i]!=num[num.size()-1-i]) return 0;
		// cout << num[i] <<" "<< num[num.size()-1-i] << endl;
	}
	return 1;
}
int main(){
    int t;
    cin >> t;
    while(t--){
		int n,m;
		cin >> n >> m;
		bool flag=0;
		for(int i=n; i<=m; i++){
			if(isprime(i) && back(i)){
				flag=1;
				cout << i << endl;
			}
		}
		if(!flag) cout << "Not found" << endl;
	}
	return 0;
}