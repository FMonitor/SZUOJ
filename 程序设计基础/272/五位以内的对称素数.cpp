#include<bits/stdc++.h>
using namespace std;
bool isprime(int x){
   if(x==0 || x==1) return 0;
   for(int i=2; i<=sqrt(x); i++){
      if(x%i==0) return 0;
   }
   return 1;
}
bool isback(int x){
   if(x<10) return 1;
   else if(x<100){
      // cout << x << endl;
      if(x%10==x/10) return 1;
   }
   else if(x<1000){
      
      if(x%10==x/100) return 1;
   }
   else if(x<10000){
      if(x%10==x/1000 && x%100/10==x/100%10) return 1;
   }
   else if(x<100000){
      if(x%10==x/10000 && x%100/10==x/1000%10) return 1;
   }
   return 0;
}
int main(){
   int n;
   cin >> n;
   while(n--){
      int num;
      cin >> num;
      // cout << 101/100 <<" " << 101%10<<endl;
      // cout << isback(num) << isprime(num) << endl;
      if(isback(num) && isprime(num)){
         cout << "Yes" << endl;
      }else cout << "No" << endl;
   }
   return 0;
}