#include<iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];
        int* p = (a + n / 2);
        int n1;
        cin >> n1;
        *p--;
        cout << *p << " ";
        *p++;
        *p++;
        cout << *p << endl;
        *p--;
        cout << *(a+n1-1);
        if(t!=0) printf("\n");
    }
    return 0;
}