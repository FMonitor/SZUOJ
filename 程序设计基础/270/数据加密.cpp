#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<vector>
using namespace std;
int main(){
   int t;
   cin >> t;
   while(t--){
      string n;
      cin >> n;
      for(int i=0; i<4; i++){
         if(n[i]>='5') n[i]-=5;
         else n[i]+=5;
      }
      swap(n[0],n[3]);
      swap(n[1],n[2]);
      cout << n << endl;
   }
   return 0;
}