#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[34];
int main(){
    cin >> n;
    while(n--){
        cin >> m;
        int maxn=-1e9;
        int minx=1e9;
        int g=0,h=0;
        int a1=0,a2=0;
        double sum=0;
        for(int i=0; i<m; i++){ 
            cin >> arr[i];
            sum+=arr[i];
            if(arr[i]>0) g++;
            if(arr[i]<0) h++;
            maxn=max(maxn,arr[i]);
            minx=min(minx,arr[i]);
        }
        sum/=m;
        for(int i=0; i<m; i++){
            if(arr[i]<sum) a1++;
            if(arr[i]>sum) a2++;
        }
        cout << fixed << setprecision(2)<<sum << " " << a2 <<" " << a1 << endl;
        cout << g <<" " << h << endl;
        cout << "max=" << maxn<<" min="<<minx<<endl<<endl;
    }
    return 0;
}