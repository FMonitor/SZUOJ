#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,d=0;
    cin >> n;
    int arr[100000];
    for(int i=0; i<n; i++) {cin >> arr[d];d++;}
    cin >> m;
    for(int i=0; i<m; i++) {cin >> arr[d];d++;}
    sort(arr,arr+d);
    for(int i=0; i<d; i++){
        cout << arr[i] <<" ";
    }
    return 0;
}