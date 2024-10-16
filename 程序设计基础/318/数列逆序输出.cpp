#include<bits/stdc++.h>
using namespace std;
int main(){
   int arr[10];
   for(int i=0; i<=9; i++){   
         cin >> arr[i];
   }
   for(int i=9; i>=0; i--){
      cout <<  arr[i];
      if(i!=0) cout <<" ";
   }
   return 0;
}