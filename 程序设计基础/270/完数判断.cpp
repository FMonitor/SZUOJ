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
      int n,cnt=0;
      vector<int> num;
      cin >> n;
      for(int i=1; i<n; i++){
         if(n%i==0) {cnt+=i;
         num.push_back(i);}
      }
      if(n==cnt){
         cout <<"yes";
      }else{
         cout << "no";
      }
      for(int i=0; i<num.size(); i++){
         cout << ',' << num[i];
      }cout << endl;
   }
   return 0;
}