#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--){
        char str[10000];
        char key[10000];
        char crypt[10000];
        cin >> str >> key;
        char *p=str,*q=key,*s=crypt;
        for(int i=0,j=0; i<strlen(str); i++,j++){
            if(j==strlen(key)) j=0;
            *(s+i)=*(p+i)+*(q+j)-'0';
            if(*(s+i)>'Z' && *(s+i)<'a' || *(s+i)>'z') *(s+i)-='Z'-'A'+1;
            cout << *(s+i);
        }
        cout << endl;
    }
    return 0;
}