#include<bits/stdc++.h>

using namespace std;

int main(){
    int ran=rand();
	int num;
	for(int i=9; i>=0; i--){
		cout << "输入一个数：";
		cin >> num;
		if(num>ran){
			cout <<endl<< "大了！还能猜"<<i<<"次" << endl;
		}if(num<ran){
			cout << endl<<"小了！还能猜"<<i<<"次" << endl;
		}if(num==ran){
			cout << endl << "猜对了！"<< endl;
			break;
		}
	}
	return 0;
}