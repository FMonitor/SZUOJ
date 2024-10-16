#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
struct node{
    string w;
    int t=1;
};
bool cmp(node a,node b){
    if(a.t==b.t) return a.w<b.w;
    return a.t>b.t;
}
int main(){
    int index=0;
    node word[30];
    string a;
    while(cin >> a){
        bool flag=0;
        if(a=="0")break;
        // cout << index <<" ";
        for(int i=0; i<index; i++){
            if(word[i].w==a){ 
                word[i].t++;
                flag=1;
                break;
            }
        }
        if(!flag){
            word[index].w=a;
            index++;
        }
    }
    std::sort(word,word+index,cmp);
    // std::cout << index;
    for(int i=0; i<index; i++){
        cout << word[i].t <<" "<<word[i].w;
        if(i!=index-1) cout << endl;
    }
    return 0;
}