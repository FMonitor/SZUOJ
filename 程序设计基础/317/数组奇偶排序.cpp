#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n;
    while(n--){
        cin >> m;
        int arr[m];
        for(int i=0; i<m; i++) 
            cin >> arr[i];
        int a=0,b=m-1;
        while(a<b){
            while(arr[a]%2==0) a++;
            while(arr[b]%2==1) b--;
            // cout << a << " " << b << endl;
            if(a<b) swap(arr[a],arr[b]);
            // for(int i=0; i<m; i++)
            //     cout << arr[i] <<" ";
            // cout << endl;
        }
        cout << m <<" ";
        for(int i=0; i<m; i++)
            cout << arr[i] <<" ";
        cout << endl;
    }
    cout << endl << endl << endl;
    return 0;
}