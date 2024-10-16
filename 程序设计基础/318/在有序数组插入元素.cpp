#include<bits/stdc++.h>
using namespace std;
int main(){
   int arr[100];
   for(int i=0; i<9; i++){   
         cin >> arr[i];
   }
   int m;
   arr[10]=0;
   cin >> m;
   if(arr[0]>m) cout << m << endl;
   for(int i=0; i<9; i++){
      cout << arr[i] << endl;
      if(m>arr[i] && arr[i+1]>=m) cout << m << endl;
      
   }
   return 0;
}