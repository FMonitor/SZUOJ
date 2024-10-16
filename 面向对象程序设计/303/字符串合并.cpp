#include<bits/stdc++.h>
using namespace std;
char* strAdd(const char* s1, const char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    char* res = new char[len1 + len2 + 1];
    for(int i=0; i<len1; i++) {
        res[i] = s1[i];
    }
    for (int i = 0; i < len2; i++) {
        res[i + len1] = s2[i];
    }
    return res;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s1[100], s2[100];
        cin >> s1 >> s2;
        cout << s1 << " " << s2 << " "<< strAdd(s1, s2) ;
        if(t!=0) cout << endl;
    }
    return 0;
}