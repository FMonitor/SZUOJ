#include<iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int* p1 = new int;
        int* p2 = new int;
        int* p3 = new int;
        cin >> *p1 >> *p2 >> *p3;
        if (*p1 < *p2) swap(*p1, *p2);
        if (*p1 < *p3) swap(*p1, *p3);
        if (*p2 < *p3) swap(*p2, *p3);
        cout << *p1 << " " << *p2 << " " << *p3 <<" "<< endl;
    }
    return 0;
}