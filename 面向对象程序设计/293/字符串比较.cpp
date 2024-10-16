#include<bits/stdc++.h>
using namespace std;
int n;
char in[100][2][100];
int cmp(char* a, char* b) {
    int out = 0;
    int al = strlen(a), bl = strlen(b);
    if(al != bl){
        if(al > bl){
            return 1;
        }else{
            return -1;
        }
    }else{
        for(int i=0; i<al; i++){
            if(a[i]>b[i]){
                out+=1;
            }else if(a[i]<b[i]){
                out-=1;
            }
        }
        return out;
    }
}
int sgn(int a){
    if(a>0){
        return 1;
    }else if(a==0){
        return 0;
    }else if(a<0){
        return -1;
    }
    return -1;
}
int main()
{
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> (in[i][0]);
        cin >> (in[i][1]);
    }
    for(int i = 0; i < n; i++){
        cout << sgn(cmp(in[i][0],in[i][1])) << endl;
    }
    return 0;
}