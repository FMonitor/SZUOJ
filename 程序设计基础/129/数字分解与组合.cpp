#include<bits/stdc++.h>
using namespace std;
int main(){
   string n;
   cin >> n;
   char a=n[0];
   n[0]=n[2];
   n[2]=a;
   if(n[0]=='0' && n[1]=='0') cout << n[2];
   else if(n[0]!='0') cout << n[0] << n[1] << n[2];
   else cout << n[1] << n[2];
   return 0;
}