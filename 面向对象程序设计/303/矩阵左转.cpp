#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int arr[2][3];
        cin >> arr[0][0] >> arr[0][1] >> arr[0][2] >> arr[1][0] >> arr[1][1] >> arr[1][2];
        cout << *((*arr) + 2) << " " << *(*(arr) + 5) <<" "<< endl;
        cout << *(*(arr) + 1) << " " << *(*(arr) + 4) <<" "<< endl;
        cout << *(*arr) << " " << *(*(arr) + 3)<<" " << endl;
    }
    return 0;
}