#include<bits/stdc++.h>
using namespace std;
bool e(double a,double b){
    if(fabs(a-b)<0.001) return 1;
    return 0;
}
int main(){
    double arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr,arr+3);
    if(arr[0]==0 || arr[1]==0 || arr[2]==0){
        cout << "非三角形" << endl;
    }else if(arr[0]+arr[1]<=arr[2]){
        cout << "非三角形" << endl;
    }else if(e(arr[0]*arr[0]+arr[1]*arr[1],arr[2]*arr[2])){
        if(arr[0]==arr[1]) cout << "等腰直角三角形" << endl;
        else cout << "直角三角形" << endl;
    }else if(arr[0]==arr[1] && arr[1]==arr[2]) cout << "等边三角形" << endl;
    else if(arr[0]==arr[1]) cout << "等腰三角形" << endl;
    else cout << "普通三角形" << endl;
    return 0;
}