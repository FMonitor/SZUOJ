#include<iostream>
using namespace std;
int main() {
    char *p[12]={
        "January","February","March",
        "April","May","June","July",
        "August","September","October",
        "November","December"};
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if (n > 12 || n < 1) cout << "error" << endl;
        else cout << *(p + n - 1) << endl;
    }
    return 0;
}
