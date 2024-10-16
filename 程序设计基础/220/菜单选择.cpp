#include<bits/stdc++.h>
using namespace std;// namespace std;
bool isprime(int a){
   if(a==0 || a==1) return false;
   for(int i=2; i<=sqrt(a); i++){
      if(a%i==0) return false;
   }
   return true;
}
int main(){
   int t;
   cin >> t;
   while(t--){
      cout << "1 计算n!\n2 输出素数\n3 判定闰年\n";
      int n;
      cin >> n;
      if(n==1){
         long long num,ans=1;
         cin >> num;
         if(num==0){
            cout << 0 << endl << endl;
            continue;
         }
         for(long long i=num; i>1; i--){
            ans*=i;
         }
         cout << ans << endl << endl;
      }else if(n==2){
         int a,b;
         cin >> a >> b;
         for(int i=a; i<=b; i++){
            if(isprime(i)) cout << i <<" ";
         }
         cout << endl << endl;
      }else if(n==3){
         int y;
         cin >> y;
         if(y%400==0 || y%4==0 && y%100 !=0){
            cout << y<<"是闰年"<<endl << endl;
         }else cout << y<<"非闰年"<<endl<<endl;
      }else cout << "INPUT ERROR!"<<endl<<endl;
   }
   return 0;
}