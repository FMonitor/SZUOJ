#include<bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    char data[n];
    vector<int> arr[n];
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        if(tmp==-1){
            continue;
        } else {
            arr[tmp].push_back(i);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";

        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j]<< " ";
        }
        if (arr[i].size() == 0) {
            cout <<-1<<" ";
        }
        cout << endl;
    }
}