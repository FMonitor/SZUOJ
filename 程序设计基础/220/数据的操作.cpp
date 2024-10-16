#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

signed main(){
   char c;
   cin >> c;
   cout << "Menu:A(dd) D(elete) S(ort) Q(uit),select one:"<< endl;
   if(c=='A') cout << "data is added" << endl;
   else if(c=='D') cout << "data is deleted" << endl;
   else if(c=='S') cout << "data is sorted";
   else if(c=='Q') exit(0);
   return 0;
}