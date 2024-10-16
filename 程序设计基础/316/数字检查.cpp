#include<bits/stdc++.h>
using namespace std;
int arr[51];
bool check(int a){
    if(a/1000 %2==0 && a/100%10%2==0 && a%100/10%2==0 && a%10%2==0) return 1;
    return 0;
}
int main(){
    int i=0;
    while(1){
        cin >> arr[i];
        i++;
        if(arr[i-1]==-1) break;
    }
    sort(arr,arr+i-1,greater<int>());
    int cnt=0;
    for(int j=i; j>0;j--) if(check(arr[j-1])) cnt++;
    cout << cnt << endl;
    for(i; i>0; i--){
        
        if(check(arr[i-1])){
            if(arr[i-1]<1000) cout << "0";
            if(arr[i-1]<100) cout << "0";
            if(arr[i-1]<10) cout << "0";
            cout << arr[i-1] << endl;
        }
    }
    return 0;
}