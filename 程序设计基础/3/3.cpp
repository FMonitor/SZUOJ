#include<iostream>
using namespace std;
int main(){
	for(int i=0; i<3; i++)
		for(int j=0; j<8; j++){
			string s;
			cin >> s;
			if(s.size()>8){
				cout << s << " ";
				continue;
			}
			else{
				for(int i=0; i<8-s.size(); i++)printf(" ");
				cout << s <<" ";
			}
		}
	return 0;
}
