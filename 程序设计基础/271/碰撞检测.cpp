#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        bool flag=0;
        int x1,y1,x2,y2,x3,y3,x4,y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        // if(x1<=x3 && x4<=x2 && y1>=y3 && y2<=y4 ||x1<=x3 && x2>=x3 && y1<=y3 && y2>=y3 || x1<=x3 && x2>=x3 && y1<=y4 && y2>=y4 || x1<=x4 && x2>=x4 && y1<=y3 && y2>=y3 || x1<=x4 && x2>=x4 && y1<=y4 && y2>=y4) cout << "YES" << endl;
        // else cout << "NO" << endl;
        for(int i=x1; i<=x2; i++){
            if(flag) break;
            for(int j=y1; j<=y2; j++){
                if(i>=x3 && i<=x4 && j>=y3 && j<=y4){
                    flag=1;
                    break;
                }
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
	return 0;
}