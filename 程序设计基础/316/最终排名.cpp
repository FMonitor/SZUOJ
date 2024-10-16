#include<bits/stdc++.h>
using namespace std;
struct team{
    int id;
    int t;
    int pos;
};
bool cmp(team a,team b){
    if(a.t==b.t) return a.pos<b.pos;
    return a.t>b.t;
}
int n,m;
team arr[10006];
int main(){
    cin >> n;
    while(n--){
        cin >> m;
        for(int i=0; i<m; i++){
            cin >> arr[i].id >> arr[i].t;
            arr[i].pos=i;
        }
        sort(arr,arr+m,cmp);
        for(int i=0; i<m; i++){
            cout << arr[i].id << " " << arr[i].t << endl;
        }
    }
    return 0;
    
}